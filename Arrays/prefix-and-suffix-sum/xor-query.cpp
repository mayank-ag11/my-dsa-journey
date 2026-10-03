/***
 * Assume you initially have an empty array say ‘ARR’. You need to return the updated array provided that some ‘Q’ number of queries were performed on this array.
 The queries are of two types:
    1. 1 ‘VAL’, for this type of query, you need to insert the integer 'VAL' to the end of the array.
    2. 2 ‘VAL’, for this type of query, you need to take the bitwise XOR of all the elements of the array with 'VAL' i.e each element of the array ‘ARR’ will be updated as ‘ARR[i]’ = ‘ARR[i]’ ^ ‘VAL’ ( ^ denotes the bitwise XOR operation).
 * Note that the ith query should be performed on the array obtained after performing (i-1)th query on the array and so on i.e the changes of each query are updated on the original array itself.
 ***/
/*
Coding Ninjas Solution:
   Time Complexity: O(Q)
   Space Complexity: O(1)

   Where 'Q' is the number of queries
*/
vector<int> xorQuery(vector<vector<int>> &queries)
{
	// Create an empty array ans
	vector<int>ans;

	// Create a variable flag
	int flag = 0;

	// Iterate over the queries
	// If the query is of type 1 then insert at the back of the array ans (queries[i][1] ^ Val)
	// Otherwise, update the value of the flag as flag ^ queries[i][1]
	for (int i = 0; i < queries.size(); i++)
	{
		if (queries[i][0] == 1)
		{
			ans.push_back(queries[i][1]^flag);
		}
		else
		{
			flag ^= queries[i][1];
		}

	}

	// Iterate through the array ans and for each element in the array update it as ans[i] = ans[i] ^ flag
	for (int i = 0; i < ans.size(); i++)
	{
		ans[i] = ans[i] ^ flag;
	}

	// Return the array ans
	return ans;
}
/* Mine
    Time: O(Q) where Q = no of queries
    Space: O(1)
*/
vector<int> xorQuery(vector<vector<int>> &queries) {
    int prefix = 0;
    for(int i = queries.size() - 1; i >= 0; i--) {     
        if(queries[i][0] == 2) {
            prefix ^= queries[i][1];
        }
    }
    vector<int> ans;
    int k = 0;
    for(int i = 0; i < queries.size(); i++) {
        if(queries[i][0] == 1) {
            ans.push_back(queries[i][1]);
            ans[k] ^= prefix;
            k++;
        }
        else {
            prefix ^= queries[i][1];
        }
    }
    return ans;
}

// Time: O(Q) where Q = no of queries
// Space: O(Q)
vector<int> xorQuery(vector<vector<int>> &queries) {
    int prefix[queries.size()], n = 0;
    prefix[n++] = 0;
    for(int i = queries.size() - 1; i >= 0; i--) {     
        if(queries[i][0] == 2) {
            prefix[n] = prefix[n-1] ^ queries[i][1];
            n++;
        }
//         else {
//             prefix[n] = prefix[n-1];
//             n++;
//         }
    }
    vector<int> ans;
    int k = 0;
    for(int i = 0; i < queries.size(); i++) {
        if(queries[i][0] == 1) {
            ans.push_back(queries[i][1]);
            ans[k] ^= prefix[n-1];
            k++;
        }
        else {
            n--;
        }
    }   
//     for(int i = 0; i < ans.size(); i++) {
//         ans[i] ^= prefix[n-1];
//         n--;
//     }
    return ans;
}

// Brute force
vector<int> xorQuery(vector<vector<int>> &queries) {
	vector<int> ans;
    
    for (int i = 0; i < queries.size(); i++) {
        int q = queries[i][0];
        int val = queries[i][1];
        
        if(q == 1)
            ans.push_back(val);
        else { // if q == 2
            for(int i = 0; i < ans.size(); i++)
                ans[i] ^= val;
        }
    }
    return ans;
}