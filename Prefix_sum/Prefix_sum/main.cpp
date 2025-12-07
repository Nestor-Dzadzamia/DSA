////
////  main.cpp
////  Prefix_sum
////
////  Created by Nestor Dzadzamia on 12.09.25.
////
//
//#include <iostream>
//using namespace std;
//int n, query, pref[1000001], numb, i, idx1, idx2;
//
//int main(int argc, const char * argv[]) {
//    cin >> n >> query;
//    
//    for (i = 1; i <= n; i++) {
//        cin >> numb;
//        pref[i] = pref[i - 1] + numb;
//    }
//    
//    for (i = 1; i <= query; i++) {
//        cin >> idx1 >> idx2;
//        cout << pref[idx2] - pref[idx1 - 1] << endl;
//    }
//}
