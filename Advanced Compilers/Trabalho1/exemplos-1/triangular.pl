fun(triangular, [arg(n, int)],
  body([
      local(a, int, nil),
      local(b, int, nil)
    ], [
      assign(id(a,local,int), id(n,arg,int): int),
      if(
        gt(id(a,local,int): int, int_literal(0): int): bool, [
          assign(id(b,local,int),
            call(triangular, [
              minus(id(n,arg,int): int, int_literal(1): int): int]): int),
          assign(id(a,local,int),
            plus(id(a,local,int): int, id(b,local,int): int): int)
        ], 
        nil)
    ],
    id(a,local,int): int)).
