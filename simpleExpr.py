def findMatchingBracket(expr):
    count = 1
    for i, s in enumerate(expr): # 0 -> len(restOfExpr)
        if s == ")":
            count -= 1
        if s == "(":
            count += 1

        if count == 0:
            return i

def eval(expr):
    rest = 0
    if expr[0] >= '0' and expr[0] <= '9':
        res = int(expr[0])
        if len(expr) == 1:
            return res
    elif expr[0] == "(":
        rest = findMatchingBracket(expr[1:]) + 1
        res = eval(expr[1:rest])

    if(rest + 2 < len(expr)):
        if expr[rest + 1] == "*":
            res *= eval(expr[rest + 2:])
        elif expr[rest + 1] == "+":
            res += eval(expr[rest + 2:])

    return res
