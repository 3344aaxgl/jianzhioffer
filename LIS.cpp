#include<iostream>
#include<vector>
using namespace std;


  struct ListNode {
      int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  };


class Solution
{
public:
  int LIS(int *arr,int length)
  {
      int *result = new int(length);
      for(int i=0;i<length;i++)
      {
          result[i] = 1;
          for(int j=0;j<i;j++)
          {
              if(arr[i]>arr[j])
              {
                  if(result[i]<result[j]+1)
                    result[i] = result[j+1];
              }
          }

      }
      delete []result;
  }
  
  vector<int> result;
  vector<int> printListFromTailToHead(ListNode* head) 
  {
      
      ListNode *p = head;
      if(p!=NULL)
      {
          if(p->next!=NULL)
              printListFromTailToHead(p->next);
          result.push_back(p->val);
      }       
      return result;         
  }

  int Max(int a[],int num)
  {
      if(num==1)
        return a[0];
      int max = Max(a,num-1);
      if(a[num-1]>max)
        return a[num-1];
      else 
        return max;
  }

};

int main()
{

    int arr[]={1,2,3,4,5,6};  
    Solution s;
    cout<<s.Max(arr,6);  
    return 0;
}