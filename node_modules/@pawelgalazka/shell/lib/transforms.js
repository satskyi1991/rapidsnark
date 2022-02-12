"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const stream_1 = require("stream");
function transformStream(transform) {
    return new stream_1.Transform({
        transform(chunk, encoding, callback) {
            const data = chunk.toString();
            const transformedOutput = transformString(transform, data);
            callback(undefined, transformedOutput);
        }
    });
}
exports.transformStream = transformStream;
function transformString(transform, data) {
    const lineSeparator = "\n";
    const dataArray = data.split(lineSeparator);
    const prefixedDataArray = dataArray.map(line => line ? transform(line) : line);
    const prefixedData = prefixedDataArray.join(lineSeparator);
    return prefixedData;
}
exports.transformString = transformString;
function setupStdoutStderrStreams(options, childProcess) {
    let stdout = childProcess.stdout;
    let stderr = childProcess.stderr;
    if (stdout && stderr) {
        if (options.transform) {
            const stdoutPrefixTransformStream = transformStream(options.transform);
            const stderrPrefixTransformStream = transformStream(options.transform);
            stdout = stdoutPrefixTransformStream;
            stderr = stderrPrefixTransformStream;
            if (!options.silent) {
                stdoutPrefixTransformStream.pipe(options.parentProcess.stdout);
                stderrPrefixTransformStream.pipe(options.parentProcess.stderr);
            }
            childProcess.stdout.pipe(stdoutPrefixTransformStream);
            childProcess.stderr.pipe(stderrPrefixTransformStream);
        }
        else if (!options.silent) {
            childProcess.stdout.pipe(options.parentProcess.stdout);
            childProcess.stderr.pipe(options.parentProcess.stderr);
        }
    }
    return {
        stderr,
        stdout
    };
}
exports.setupStdoutStderrStreams = setupStdoutStderrStreams;
exports.prefixTransform = prefix => output => `${prefix} ${output}`;
//# sourceMappingURL=transforms.js.map