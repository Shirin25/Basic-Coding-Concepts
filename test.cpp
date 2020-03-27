#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;
void longestseries(vector<int>&arr)
{
    unordered_map<int,bool>map;
     for(int ele:arr) map[ele]=true;

     int size=-1;
     int number=-1;

     for(auto keys:map)
     {
         if(keys.second)
         
         {
             if(map.find(keys.first-1)!=map.end())
             {
                 map[keys.first]=false;
             }
         }
     }

     for(auto keys:map)
     {
         if(keys.second)
         {
             int num=keys.first+1;
             int smallsize=1;

             while(map.find(num)!=map.end())
             {
                 num++;
                 smallsize++;
             }

             if(smallsize>size)
             {
                 size=smallsize;
                 number=keys.first;
             }

         }
     }

     for(int i=0;i<size;i++)
     {
         cout<<number+i<<" ";
     }

     cout<<endl;
}

void leetcode350(vector<int>&arr1,vector<int>&arr2)
{
    unordered_map<int,int>map1;
    unordered_map<int,int>map2;

    for(int ele:arr1)
    {
       
    }

   
    
}

int main()
{
    vector<int> arr{0,1,2,100,99,98,7,97,96,95,94,12,3,4,5,10,6,8};
   // longestseries(arr);
   vector<int> arr1 = {4,9,5};
   vector<int> arr2= {9,4,9,8,4};
 leetcode350(arr1,arr2);
    return 0;
}