# https://www.marscode.cn/practice/4vvlv96y48d1od

def solution(expression):
    # 初始化两个栈
    num_stack = []
    op_stack = []
    
    # 定义操作符优先级
    precedence = {'+': 1, '-': 1, '*': 2, '/': 2}
    
    # 遍历表达式
    i = 0
    while i < len(expression):
        char = expression[i]
        
        if char.isdigit():
            # 处理数字
            num = int(char)
            num_stack.append(num)
        
        elif char in precedence:
            # 处理操作符
            while op_stack and op_stack[-1] != '(' and precedence[char] <= precedence[op_stack[-1]]:
                # 弹出操作符并进行计算
                op = op_stack.pop()
                num2 = num_stack.pop()
                num1 = num_stack.pop()
                result = perform_operation(num1, num2, op)
                num_stack.append(result)
            op_stack.append(char)
        
        elif char == '(':
            # 处理左括号
            op_stack.append(char)
        
        elif char == ')':
            # 处理右括号
            while op_stack and op_stack[-1] != '(':
                op = op_stack.pop()
                num2 = num_stack.pop()
                num1 = num_stack.pop()
                result = perform_operation(num1, num2, op)
                num_stack.append(result)
            op_stack.pop()  # 弹出左括号
        
        i += 1
    
    # 处理剩余的操作符
    while op_stack:
        op = op_stack.pop()
        num2 = num_stack.pop()
        num1 = num_stack.pop()
        result = perform_operation(num1, num2, op)
        num_stack.append(result)
    
    # 返回最终结果
    return num_stack[0]

def perform_operation(num1, num2, op):
    if op == '+':
        return num1 + num2
    elif op == '-':
        return num1 - num2
    elif op == '*':
        return num1 * num2
    elif op == '/':
        return num1 // num2  # 注意：只保留整数结果

if __name__ == "__main__":
    #  You can add more test cases here
    print(solution("1+1") == 2)
    print(solution("3+4*5/(3+2)") == 7)
    print(solution("4+2*5-2/1") == 12)
    print(solution("(1+(4+5+2)-3)+(6+8)") == 23)