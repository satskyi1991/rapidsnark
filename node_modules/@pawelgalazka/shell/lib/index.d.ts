import { execSync, spawn } from "child_process";
import { TransformFunction } from "./transforms";
export { prefixTransform } from "./transforms";
export declare class ShellError extends Error {
    constructor(message: string);
}
declare type NormalizedStdioOptions = Array<"pipe" | "ignore" | "inherit">;
export interface IShellOptions {
    cwd?: string;
    env?: NodeJS.ProcessEnv;
    timeout?: number;
    async?: boolean;
    nopipe?: boolean;
    silent?: boolean;
    transform?: TransformFunction;
    parentProcess?: NodeJS.Process;
    spawn?: typeof spawn;
    execSync?: typeof execSync;
}
export interface IAsyncShellOptions extends IShellOptions {
    async: true;
}
export interface ISyncShellOptions extends IShellOptions {
    async: false | undefined;
}
export interface INormalizedShellOptions extends IShellOptions {
    env: NodeJS.ProcessEnv;
    stdio: NormalizedStdioOptions;
    spawn: typeof spawn;
    execSync: typeof execSync;
    parentProcess: NodeJS.Process;
}
export declare function shell(command: string, options: IAsyncShellOptions): Promise<string | null>;
export declare function shell(command: string, options?: ISyncShellOptions): string | null;
export declare function shell(command: string, options?: IShellOptions): Promise<string | null> | string | null;
