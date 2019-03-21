#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int partial(vector<int> arr, int i, int j, int k);
vector<int> quicksort(vector<int> partition);

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++){
        vector<int> c = commands[i];
        answer.push_back(partial(array, c[0]-1,c[1],c[2]));
    }
    return answer;
}

int partial(vector<int> arr, int i, int j, int k){
    vector<int> partition;
    partition.clear();
    partition.assign(arr.begin()+i, arr.begin()+j);
    vector<int> result = quicksort(partition);
    return result[k-1];
}

vector<int> quicksort(vector<int> partition){
    if (partition.size() <= 1)return partition;
    int pivot = partition[0];
    vector<int> left;
    vector<int> right;
    vector<int> center;
    for(int i=0; i< partition.size(); i++){
        if(partition[i] < pivot)left.push_back(partition[i]);
        else if(partition[i] > pivot)right.push_back(partition[i]);
        else center.push_back(partition[i]);
    }
    vector <int> result;
    left = quicksort(left);
    right = quicksort(right);
    result.reserve(left.size()+center.size()+right.size());
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), center.begin(), center.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}