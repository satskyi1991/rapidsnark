"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const child_process_1 = require("child_process");
const transforms_1 = require("./transforms");
var transforms_2 = require("./transforms");
exports.prefixTransform = transforms_2.prefixTransform;
class ShellError extends Error {
    constructor(message) {
        message = message && message.split("\n")[0]; // assign only first line
        super(message);
        this.name = "ShellError";
    }
}
exports.ShellError = ShellError;
function shellAsync(command, options) {
    return new Promise((resolve, reject) => {
        const spawnOptions = {
            cwd: options.cwd,
            env: options.env,
            shell: true,
            stdio: options.stdio
        };
        const asyncProcess = options.spawn(command, spawnOptions);
        let output = null;
        const { stdout } = transforms_1.setupStdoutStderrStreams(options, asyncProcess);
        asyncProcess.on("error", (error) => {
            reject(new ShellError(`Failed to start command: ${command}; ${error.toString()}`));
        });
        asyncProcess.on("close", (exitCode) => {
            if (exitCode === 0) {
                resolve(output);
            }
            else {
                reject(new ShellError(`Command failed: ${command} with exit code ${exitCode}`));
            }
        });
        if (stdout) {
            stdout.on("data", (buffer) => {
                output = buffer.toString();
            });
        }
        if (options.timeout) {
            setTimeout(() => {
                asyncProcess.kill();
                reject(new ShellError(`Command timeout: ${command}`));
            }, options.timeout);
        }
    });
}
function shellSync(command, options) {
    try {
        const execSyncOptions = {
            cwd: options.cwd,
            env: options.env,
            stdio: options.stdio,
            timeout: options.timeout
        };
        const buffer = options.execSync(command, execSyncOptions);
        if (buffer) {
            const output = options.transform
                ? transforms_1.transformString(options.transform, buffer.toString())
                : buffer.toString();
            if (!options.silent) {
                options.parentProcess.stdout.write(output);
            }
            return output;
        }
        return null;
    }
    catch (error) {
        const message = options.transform
            ? transforms_1.transformString(options.transform, error.message)
            : error.message;
        throw new ShellError(message);
    }
}
function shell(command, options = {}) {
    const parentProcess = options.parentProcess || process;
    const stdio = options.nopipe
        ? options.silent
            ? ["inherit", "ignore", "ignore"]
            : ["inherit", "inherit", "inherit"]
        : ["inherit", "pipe", "pipe"];
    const normalizedOptions = Object.assign({}, options, { env: Object.assign({ FORCE_COLOR: "1" }, (options.env || parentProcess.env)), execSync: options.execSync || child_process_1.execSync, parentProcess, spawn: options.spawn || child_process_1.spawn, stdio });
    return normalizedOptions.async
        ? shellAsync(command, normalizedOptions)
        : shellSync(command, normalizedOptions);
}
exports.shell = shell;
//# sourceMappingURL=index.js.map