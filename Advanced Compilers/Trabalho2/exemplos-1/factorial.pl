fun(factorial, [arg(n, int)],
  body([
      local(r, int, int_literal(1): int)
    ], 
    if(
      gt(id(n,arg,int): int, int_literal(0): int): bool, 
      assign(id(r,local,int),
        times(id(n,arg,int): int,
          call(factorial, [
              minus(id(n,arg,int): int, int_literal(1): int): int
            ]): int): int), 
      nil),
    id(r,local,int): int)).
