/***
 * You have been given an integer array/list (ARR) of size N. You have to return an array/list PRODUCT such that PRODUCT[i] is equal to the product of all the elements of ARR except ARR[i]
 * Each product can cross the integer limits, so we should take modulo of the operation.
 * Take MOD = 10^9 + 7 to always stay in the limits.
 ***/
// Mine | Time: O(n), Space: O(1)
int mod = 1000000007;
int *getProductArrayExceptSelf(int *arr, int n)
{
    int *ans = new int[n];
    int prod = 1, zero = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0)
            zero++;
        else
            prod = (prod * arr[i]) % mod;
    }
    if(zero >= 2) {
        for(int i = 0; i < n; i++)
            ans[i] = 0;
    }
    else if(zero == 1) {
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0)
                ans[i] = prod;
            else
                ans[i] = 0;
        }
    }
    else {
        for(int i = 0; i < n; i++)
        	ans[i] = prod / arr[i];
    }
    
    return ans;
}

// Coding Ninjas Solutions
/*
    Time Complexity : O(N)
    Space complexity : O(N)

    where N is the size of the input array
*/
/*
    -------------- We can also use this approach. --------------
    Use property of log to multiply large numbers

    x = a * b * c * d
    log(x) = log(a * b * c * d)
    log(x) = log(a) + log(b) + log(c) + log(d)
    x = antilog(log(a) + log(b) + log(c) + log(d))
    Traverse the array and find the sum of log of all the elements.
    Then again traverse through the array and find the product using this formula.
    antilog((log(a[0]) + log(a[1]) +...... + log(a[n-1])) - log(a[i]))
    This equals to product of all the elements except a[i], i.e antilog(sum- log(a[i])).
*/
int multiply(int a, int b)
{
    int mod = 1e9 + 7;
    long long ret = a % mod;
    ret *= (b % mod);
    ret = ret % mod;
    return ret;
}

//Calculate the suffix Array
int *getPrefixArray(int *arr, int n)
{
    int productTillNow = 1L;

    int *prefixArray = new int[n];

    for (int i = 0; i < n; i++)
    {
        prefixArray[i] = productTillNow;
        productTillNow = multiply(productTillNow, arr[i]);
    }

    return prefixArray;
}

//Calculate the prefix Array
int *getSuffixArray(int *arr, int n)
{
    int productTillNow = 1L;

    int *suffixArray = new int[n];

    for (int i = n - 1; i >= 0; i--)
    {
        suffixArray[i] = productTillNow;
        productTillNow = multiply(productTillNow, arr[i]);
    }

    return suffixArray;
}

int *getProductArrayExceptSelf(int *arr, int n)
{
    //Array storing the product of all elements before the current element
    int *prefixArray = getPrefixArray(arr, n);

    //Array storing the product of all elements after the current element
    int *suffixArray = getSuffixArray(arr, n);

    //Array to store the answer
    int *answerArray = new int[n];

    for (int i = 0; i < n; i++)
    {
        //Answer is the product of all elements before and after the current element.
        answerArray[i] = multiply(suffixArray[i], prefixArray[i]);
    }

    delete prefixArray;
    delete suffixArray;

    //Return the answer
    return answerArray;
}

/*
    Time Complexity : O(N)
    Space complexity : O(1)

    where N is the size of the input array
*/
int multiply(int a, int b)
{
    int mod = 1e9 + 7;
    long long ret = a % mod;
    ret *= (b % mod);
    ret = ret % mod;
    return ret;
}

int *getProductArrayExceptSelf(int *arr, int n)
{
    int *output = new int[n];
    int product = 1;

    for (int i = 0; i < n; ++i) 
    {
        output[i] = product;
        product = multiply(product, arr[i]);
    }

    product = 1;

    for (int i = n - 1; i >= 0; --i) 
    {
        output[i] = multiply(product, output[i]);
        product = multiply(product, arr[i]);
    }

    return output;
}