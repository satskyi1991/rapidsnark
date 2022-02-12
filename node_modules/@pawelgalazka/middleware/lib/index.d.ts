export declare type MiddlewareThunk<T> = (args: T) => any;
export declare type Middleware<T> = (next: MiddlewareThunk<T>) => MiddlewareThunk<T>;
export declare function middleware<T>(middlewares: Array<Middleware<T>>): MiddlewareThunk<T>;
