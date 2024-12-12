#include <iostream>
int rec_fun1(int num)//factorial function
{
  if (num==1) return 1;
  num = num * rec_fun1(num-1);
  return num;
}

void rec_fun2(int* arr, int size, int index)//fill the array
{
  arr[0] = 3;
  if(index < size){
    arr[index+1] = arr[index]+35;
    rec_fun2(arr, size, index+1);
  }
}

int rec_fun3(int* arr ,int low, int high, int num)//binary search, recursive
{
  int middle = (high+low)/2;

  if(arr[middle]==num) return middle;
  else if (arr[middle]>num){
    return rec_fun3(arr, low, middle-1, num);
  }else if (arr[middle]<num){
    return rec_fun3(arr, middle+1, high, num);
  }else return -1;
}

/*int Bi_search(int* arr, int size, int num){
  int low = 0;
  int high = size-1;
  int middle;

  while(low!=high){

    middle = (high+low)/2; // set middle to middle
    std::cout << "middle is: " << middle << std::endl;

    if(arr[middle]==num)return middle; // if the middle number is what we want, return it.

    else if (arr[middle] > num) high = middle-1; // if middle number is larger, we make the element below it the new high

    else low = middle+1; // if middle number is smaller, we make the element above it the new low


    std::cout << "high is " << high << std::endl;
    std::cout << "low is " << low << std::endl;
  }

  return -1;
}
*/

int main() {
  std::string for_input;
  std::cout << "STOP! ENTER SOMETHING BELOW:\n";
  std::cin >> for_input;

  int sum = rec_fun1(3);
  std::cout << sum << std::endl;
  int arr[10];
  rec_fun2(arr, 10, 0);
    for(int count = 0; count < 10; count++){
        std::cout << arr[count] << " ";
    }
    std::cout << std::endl;
  int found = rec_fun3(arr, 0, 9, 73);
  //int found2 = Bi_search(arr,10, 73);

  std::cout << found << std::endl;
  //std::cout << found2 << std::endl;

  return 0;
}
