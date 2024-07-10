#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
//order_of_key (k) : Number of items strictly smaller than k 
//find_by_order(k) : K-th element in a set (counting from zero)
//there are some issue in this way of ordered multiset...so it is better if we maintain a normal multiset with same insertions and deletions to find the count and stuff.
//find doesnt work in this
//there is no count
int main(){
    //this is a multiset
    ordered_set yo;
    yo.insert(1);
    yo.insert(2);
    yo.insert(3);
    yo.insert(1);
    cout<<*yo.lower_bound(2)<<endl;
    yo.erase(yo.upper_bound(1));
    cout<<*yo.begin();

}
