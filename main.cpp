#include <iostream>
#include <vector>
using namespace std;

// O(n^2) time | O(n) space
vector<int> arrayOfProductsMyAlgorithm(vector<int> &array) {
    vector<int> result(array.size());// O(n) space
    for(int i = 0; i < array.size(); i++) {// O(n) time
        int runningProduct = 1;// O(1) space
        int left = i - 1;// O(1) space
        int right = i + 1;// O(1) space
        while(left >= 0) {// O(n) time NESTED
            runningProduct *= array[left];// O(1) time
            left--;// O(1) time
        }
        while(right < array.size()) {// O(n) time NESTED
            runningProduct *= array[right];// O(1) time
            right++;// O(1) time
        }
        result[i] = runningProduct;// O(1) time
    }
    return result;
}

// O(n^2) time | O(n) space
vector<int> arrayOfProductsNested(vector<int> &array) {
    vector<int> result(array.size());// O(n) space
    for(int i = 0; i < array.size(); i++) {// O(n) time
        int runningProduct = 1;// O(1) space
        for(int j = 0; j < array.size(); j++) {// O(n) time NESTED
            if(i != j) {// O(1) time
                runningProduct *= array[j];// O(1) time | O(1) space
            }
        }
        result[i] = runningProduct;// O(1) time | O(1) space
    }
    return result;
}

// O(n) time | O(n) space
vector<int> arrayOfProductsArrays(vector<int> &array) {
    vector<int> result(array.size(), 1);// O(n) space
    vector<int> left(array.size(), 1);// O(n) space
    vector<int> right(array.size(), 1);// O(n) space
    int runningProduct = 1;// O(1) space
    for(int i = 0; i < array.size(); i++) {// O(n) time
        left[i] = runningProduct;// O(1) time
        runningProduct *= array[i];// O(1) time
    }
    runningProduct = 1;// O(1) time
    for(int i = array.size() - 1; i >= 0; i--) {// O(n) time
        right[i] = runningProduct;// O(1) time
        runningProduct *= array[i];// O(1) time
    }
    for(int i = 0; i < array.size(); i++) {// O(n) time
        result[i] = left[i] * right[i];// O(1) time
    }
    return result;
}

// O(n) time | O(n) space
vector<int> arrayOfProductsSingleArray(vector<int> &array) {
    vector<int> result(array.size(), 1);// O(n) space
    int runningProduct = 1;// O(1) space
    for(int i = 0; i < array.size(); i++) {// O(n) time
        result[i] = runningProduct;// O(1) time
        runningProduct *= array[i];// O(1) time
    }
    runningProduct = 1;
    for(int i = array.size() - 1; i >= 0; i--) {// O(n) time
        result[i] *= runningProduct;// O(1) time
        runningProduct *= array[i];// O(1) time
    }
    return result;
}

int main() {
    vector<int> input = {5, 1, 4, 2};
    vector<int> myResult = arrayOfProductsMyAlgorithm(input);
    vector<int> nestedResult = arrayOfProductsNested(input);
    vector<int> arrayResult = arrayOfProductsArrays(input);
    vector<int> singleArrayResult = arrayOfProductsSingleArray(input);
    cout << "My Algorithm : " << endl;
    for(int element : myResult) {
        cout << element << " ";
    }
    cout << endl;
    cout << endl;
    cout << "Nested Algorithm : " << endl;
    for(int element : nestedResult) {
        cout << element << " ";
    }
    cout << endl;
    cout << endl;
    cout << "Multiple Arrays Algorithm : " << endl;
    for(int element : arrayResult) {
        cout << element << " ";
    }
    cout << endl;
    cout << endl;
    cout << "Single Array Algorithm : " << endl;
    for(int element : singleArrayResult) {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}
