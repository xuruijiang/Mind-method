class_num = 57
avg_salary = "万"
message = "学Python就来黑马程序员 %d,月薪过%s不是梦" % (class_num, avg_salary)
print(message)
print(f"我是一个{class_num},继续格式化{avg_salary},完成 {message}")
print(f"表达式格式化{1 + 8}")


name = "黑马"
stock_price = 19.99
stock_code = "332200"
stock_price_daily_growth_factor = 1.2
growth_days = 7
finally_stock_price = stock_price * stock_price_daily_growth_factor ** growth_days
print(f"公司:{name},股票代码;{stock_code},起始单价:{stock_price},最终单价:{finally_stock_price}")
print("公司:%s,股票代码:%s，起始单价:%f,最终单价:%.2f" % (name, stock_code, stock_price, finally_stock_price))
# name = input("请告诉我你是哪家公司:")
# stock_price = input()
stock_price = int(stock_price)
print(name)
print(stock_price + 2)

chooseOne = True
chooseTwo = False
print(chooseOne)
print(chooseTwo)
chooseOne = 10 < 5
chooseTwo = 10 > 5
print(chooseOne)
print(chooseTwo)
chooseOne = 5 == 5
print(chooseOne)

