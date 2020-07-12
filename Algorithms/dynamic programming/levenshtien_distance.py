

import numpy as np 


strings_1 = ['elephant', 'park', 'hyndai']
strings_2 = ['relevant', 'spark', 'honda'] 




def levenshtien_distance_dp (string1, string2):
    dp = np.zeros((len(string1)+1, len(string2)+1), dtype= int) 
    for i in range(1, dp.shape[0]): dp[i,0] = dp[i-1, 0]+1
    for j in range(1, dp.shape[1]): dp[0,j] = dp[0, j-1]+1

    for i in range(1, dp.shape[0]):
        for j in range(1, dp.shape[1]) :
            if string1[i-1] == string2[j-1] : 
                dp[i][j] = dp[i-1][j-1] 
            else : 
                dp[i][j] = min(dp[i-1][j-1] +2,
                               min(dp[i][j-1] +1, dp[i-1][j] +1))
    print(dp) 
    print("distance between {} and {} is {} \n".format(string1, string2, dp[len(string1)][len(string2)]))



for s1, s2 in zip(strings_1, strings_2):
    levenshtien_distance_dp(s1, s2 ) 