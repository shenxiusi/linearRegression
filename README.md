# shenxiusi
This is a demo for linearRegression.
It can soak data from 28.txt and determin for each stock ID, what is its linearRegression function.
   Example:
   Stock No   |   data1   |   data2   
    600000	-0.462206333	6.8579
    600000	0.031339031	13.877
    600000	-0.190607735	-20.7811
    600000	-0.034129693	-2.6972
    600000	-0.175500589	-11.7043
    600000	-0.011428571	-9.393
    600000	0.105491329	-8.1181
    600000	0.08496732	6.6122
    600000	0.174698795	-0.6083
    600000	0.113846154	10.1228
    600000	-0.08747698	28.7464
    600000	0.071644803	2.8652
    600000	1.006591337	50.248
    600000	0.253871422	16.5076
    600000	0.369386228	17.8641
    600000	0.434818256	42.8326
    600000	0.005714286	-8.1374
    600000	-0.329545455	-37.402
    600000	-0.378531073	-23.7064
    600000	-0.29	-19.2207
    600000	-0.151728553	-23.9526
    600000	0.654339623	29.3339
    600000	0.050182482	25.0161
    600000	-0.14639444	-6.6776
    600000	0.103816794	16.5939
    600000	0.050253573	-6.4496
    600000	-0.402985075	-23.3326
    600000	-0.047058824	9.7569
    600000	-0.043981481	4.1763
    600000	0.099273608	2.2712
    600000	-0.27753304	-7.148
    600000	-0.132113821	-17.3096
    600000	-0.005854801	-9.9012
    600000	0.051825677	-0.2737
    600000	-0.089585666	-3.0141
    600000	-0.092250923	-8.692
    600000	0.344173442	5.6229
    600000	0.021169355	-4.5828
    600000	-0.182625864	-12.8508
    600000	0.218599034	8.0862
    600000	-0.065411298	-5.5969
    600000	0.030752916	-6.8109
    600000	-0.068930041	-0.4399
    600000	0.077348066	14.0758
    600000	0.609230769	33.9438
    
    
Result is:
   回归方程式:    Y = 0.00240 + 51.25590*X1
 
   回归显著性检验: 
   回归平方和：   8998.5462  回归方差：   8998.5462 
   剩余平方和：   5530.1010  剩余方差：    128.6070 
   离差平方和：  14528.6472  标准误差：     11.3405 
   F   检  验：     69.9693  相关系数：      0.7870 
   剩余分析: 
      观察值      估计值      剩余值    剩余平方 
        6.86      -23.69       30.55      933.08 
       13.88        1.61       12.27      150.51 
      -20.78       -9.77      -11.01      121.30 
       -2.70       -1.75       -0.95        0.90 
      -11.70       -8.99       -2.71        7.35 
       -9.39       -0.58       -8.81       77.61 
       -8.12        5.41      -13.53      182.99 
        6.61        4.36        2.25        5.08 
       -0.61        8.96       -9.57       91.49 
       10.12        5.84        4.29       18.36 
       28.75       -4.48       33.23     1104.08 
        2.87        3.67       -0.81        0.66 
       50.25       51.60       -1.35        1.82 
       16.51       13.01        3.49       12.20 
       17.86       18.94       -1.07        1.15 
       42.83       22.29       20.54      422.02 
       -8.14        0.30       -8.43       71.11 
      -37.40      -16.89      -20.51      420.79 
      -23.71      -19.40       -4.31       18.55 
      -19.22      -14.86       -4.36       19.00 
      -23.95       -7.77      -16.18      261.73 
       29.33       33.54       -4.21       17.70 
       25.02        2.57       22.44      503.62 
       -6.68       -7.50        0.82        0.68 
       16.59        5.32       11.27      127.02 
       -6.45        2.58       -9.03       81.50 
      -23.33      -20.65       -2.68        7.18 
        9.76       -2.41       12.17      148.02 
        4.18       -2.25        6.43       41.32 
        2.27        5.09       -2.82        7.95 
       -7.15      -14.22        7.07       50.05 
      -17.31       -6.77      -10.54      111.10 
       -9.90       -0.30       -9.60       92.23 
       -0.27        2.66       -2.93        8.60 
       -3.01       -4.59        1.58        2.48 
       -8.69       -4.73       -3.97       15.73 
        5.62       17.64      -12.02      144.49 
       -4.58        1.09       -5.67       32.15 
      -12.85       -9.36       -3.49       12.20 
        8.09       11.21       -3.12        9.74 
       -5.60       -3.35       -2.25        5.05 
       -6.81        1.58       -8.39       70.38 
       -0.44       -3.53        3.09        9.55 
       14.08        3.97       10.11      102.19 
       33.94       31.23        2.71        7.37 

