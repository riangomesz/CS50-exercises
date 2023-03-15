def calculate_coins(change):
    coins = [1, 5, 10, 25, 50, 100] # coin values available in cents
    coin_values = ['1 cent', '5 cents', '10 cents', '25 cents', '50 cents', '1 dollar'] # names of the corresponding coins
    num_coins = [0] * len(coins) # initialize the number of coins of each value with zero
    
    change = int(change * 100) # convert the change value to cents
    
    # iterate from the highest to the lowest coin value, adding the necessary coins to the result
    for i in range(len(coins)-1, -1, -1):
        while change >= coins[i]:
            change -= coins[i]
            num_coins[i] += 1
    
    result = []
    # iterate over the number of coins of each value, adding the value and quantity of each coin to the result
    for i in range(len(num_coins)):
        if num_coins[i] > 0:
            result.append(f"{num_coins[i]} {coin_values[i]}")
    
    return result
