import { ChildProcess } from "child_process";
import { Readable, Transform } from "stream";
import { INormalizedShellOptions } from "./index";
export declare type TransformFunction = (output: string) => string;
export declare function transformStream(transform: TransformFunction): Transform;
export declare function transformString(transform: TransformFunction, data: string): string;
export declare function setupStdoutStderrStreams(options: INormalizedShellOptions, childProcess: ChildProcess): {
    stderr: Readable;
    stdout: Readable;
};
export declare const prefixTransform: (prefix: string) => TransformFunction;
