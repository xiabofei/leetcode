#include <vector>
#include <iostream>
#include <string>

using namespace std;

// 冒泡
void bubble_sort(std::vector<int> &nums){
	for(int i=0; i<nums.size()-1; i++){
		for(int j=0; j<nums.size()-1-i; j++){
			if(nums[j+1]<nums[j]){
				int tmp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = tmp;
			}
		}
	}
}

// 插入
void insert_sort(std::vector<int> &nums){
	for(int i=1; i<nums.size(); i++){
		int curr = nums[i];
		int j = i;
		while(j>0 && nums[j-1]>curr){
			nums[j] = nums[j-1];
			j--;
		}
		nums[j] = curr;
	}
}

// 选择
void selection_sort(std::vector<int> &nums){
	for(int i=0; i<nums.size()-1; i++){
		int min_idx = i;
		for(int j=i+1; j<nums.size(); j++){
			if(nums[j]<nums[min_idx]){
				min_idx=j;
			}
		}
		int tmp = nums[min_idx];
		nums[min_idx] = nums[i];
		nums[i] = tmp;
	}
}

// 希尔 (改进的selection sort)
void shell_sort(std::vector<int> &nums){
	// 确定每一轮的步长
	for(int step = nums.size() >> 1; step>=1; step >>= 1){
		// 每个子数组的起始位置
		for(int begin=0; begin<step; begin++){
			// 对每个子数组进行选择排序
			for(int i=begin; i<nums.size()-1; i+=step){
				int min_idx = i;
				for(int j=i+step; j<nums.size(); j+=step){
					if(nums[j]<nums[min_idx]){
						min_idx = j;
					}
				}
				int tmp = nums[min_idx];
				nums[min_idx] = nums[i];
				nums[i] = tmp;
			}
		}
	}
}

// 归并
void merge_two_sorted_vec(
	std::vector<int> &nums, 
	int b, int m, int e, 
	std::vector<int> &tmp)
{
	int l_b = b;
	int r_b = m;
	int tmp_b = b;
	while(l_b<m && r_b<e){
		if(nums[l_b]<nums[r_b]){
			tmp[tmp_b++] = nums[l_b++];
		}
		else{
			tmp[tmp_b++] = nums[r_b++];
		}
	}
	while(l_b<m){
		tmp[tmp_b++] = nums[l_b++];
	}
	while(r_b<e){
		tmp[tmp_b++] = nums[r_b++];
	}
	for(int i=b; i<e; i++){
		nums[i] = tmp[i];
	}
}
void merge_sort(
	std::vector<int> &nums,
	int b, int e,
	std::vector<int> &tmp)
{
	int m = (b+e)/2;
	if(b==m){return;}
	merge_sort(nums, b, m, tmp);
	merge_sort(nums, m, e, tmp);
	merge_two_sorted_vec(nums, b, m, e, tmp);
}

// 快排
void quick_sort(std::vector<int> &nums, int b, int e){
	if(b >= e){return;}
	int lp = b;
	int rp = e;
	while(lp < rp){
		// 以最左侧的为基准 则先动右侧的指针 最次右侧移动到b的位置 b lp rp三者重合
		while(lp<rp && nums[rp]>=nums[b]){rp--; }
		while(lp<rp && nums[lp]<=nums[b]){lp++; }
		swap(nums[lp], nums[rp]);
	}
	swap(nums[b], nums[rp]);
	quick_sort(nums, b, rp-1);
	quick_sort(nums, rp+1, e);
}

// 堆排
void adjust_heap(std::vector<int> &nums, int b, int e){
	// 终止条件是向下调整到非叶子节点
	while(b<=e/2-1){
		// 大顶堆 -- 选出值较大的child
		// 小顶堆 -- 选出值较小的child
	    int child = 2*b+1;
		if(child+1<e && nums[child]<nums[child+1]){
			child += 1;
		}
		// 满足二叉堆的条件 则停止调整
		if(nums[b]>nums[child]){break;}
		// 否则调整parent和child节点
		swap(nums[b], nums[child]);
		// parent节点下沉 继续调整
		b = child;
	}
}
void heap_sort(std::vector<int> &nums){
	// 建堆 -- 调整非叶子节点
	for(int p = nums.size()/2-1; p>=0; p--){
		adjust_heap(nums, p, nums.size());
	}
	// 排序 -- 每次从堆顶拿出一个元素
	for(int p = nums.size(); p>0; p--){
		swap(nums[0], nums[p-1]);
		adjust_heap(nums, 0, p-1);
	}
}


int main(int argc, char const *argv[])
{
	
	// static const int arr[] = {10, 80, 70, 100, 90, 30, 20};
	static const int arr[] = { 23, 65, 12, 3, 8, 76, 345, 90, 21, 75, 34, 61};
	// static const int arr[] = {80, 100, 70};
	vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	vector<int> tmp (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	// bubble_sort(vec);
	// insert_sort(vec);
	// selection_sort(vec);
	// shell_sort(vec);
	// merge_sort(vec, 0, vec.size(), tmp);
	// quick_sort(vec, 0, vec.size()-1);
	heap_sort(vec);
	for ( int i = 0; i<vec.size(); i++){cout << vec[i] << endl;}
}
