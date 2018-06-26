preSucceed = false

def clickSucceed() :
    if preSucced == false :
        preSucceed = true
    else :
        preSucceed = false
    
    return preSucceed


i = 0
N = 100
click[100];
for ii in range(100):
    click[ii] = false;
n_click = 0

while (n_click < 90) :
    i = i + 1
    for (j in 1 to N) :
        if (click[j] == false) :
            succeed = clickSucceed()
            click[j] = succeed 

            if (succeed == true) :
                n_click = n_click + 1
print(i);
