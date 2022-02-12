# middleware
Simple middleware pattern engine

```
npm install --save @pawelgalazka/middleware
```

```ts
import { middleware, Middleware } from '@pawelgalazka/middleware'

interface IMiddlewareArguments {
  arg1: string
  arg2: string
}

type CustomMiddleware = Middleware<IMiddlewareArguments>


const middleware1: CustomMiddleware = next => ({arg1, arg2}) => {
  next({
    arg1: arg1 + 'e'
    arg2: arg2 + 'f'
  })

}

const middleware2: CustomMiddleware = next => ({arg1, arg2}) => {
  console.log('ARGS', arg1, arg2)
}

middleware([middleware1, middleware2])({arg1: 'a', arg2: 'b'})
```

```
ARGS ae bf
```
