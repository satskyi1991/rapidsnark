"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
function middleware(middlewares) {
    const middleware = middlewares.reduceRight((nextMiddleware, previousMiddleware) => next => previousMiddleware(nextMiddleware(next)));
    return middleware(() => null);
}
exports.middleware = middleware;
//# sourceMappingURL=index.js.map