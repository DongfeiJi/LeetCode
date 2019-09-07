πÈ≤¢≈≈–Ú∞Ê±æ2£∫
#include<iostream>
using namespace std;

vector<int> mergeHelper(vector<int> &a, int left , int right){
	if(left == right){
		return vector<int> (1, a[left]);
	}
	int mid = left + (left + right) / 2;
	vector<int> l = mergeHelper(a, left, mid);
	vector<int> r = mergeHelper(a, mid + 1, right);
	//merge
	vector<int> tmp;
	int ll = 0, rr = 0;
	while(ll < l.size() && rr < r.size()){
		if(l[ll] < r[rr]){
			tmp.push_back(l[ll++]);
		}
		else{
			tmp.push_back(r[rr++]);
		}
	}
	while(ll < l.size()){
		tmp.push_back(l[ll++]);
	}
	while(rr < r.size()){
		tmp.push_back(r[rr++]);
	}
	return tmp;
}

void mergeSort(vector<int> &a){
	a = mergeHelper(a, 0,a.size() - 1);
}

int main(){
    int arr[9]={99,11,72,62,53,4,44,21,14};
    int length = len(arr);
    quickSort(arr,length);
return 0;
}