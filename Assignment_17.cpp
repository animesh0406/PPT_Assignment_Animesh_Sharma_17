#include<bits/stdc++.h>
using namespace std;
/*
<aside>
💡 **Question 1**

Given a string `s`, *find the first non-repeating character in it and return its index*. If it does not exist, return `-1`.

</aside>
*/
int firstUniqChar(string s) {
        vector<int> v(26,0);
		for(char c : s) v[c - 'a']++;
		for(int i = 0; i < s.length(); i++){
			if(v[s[i] - 'a'] == 1) return i;
		}
		return -1;
}


/*
<aside>
💡 **Question 2**

Given a **circular integer array** `nums` of length `n`, return *the maximum possible sum of a non-empty **subarray** of* `nums`.

A **circular array** means the end of the array connects to the beginning of the array. Formally, the next element of `nums[i]` is `nums[(i + 1) % n]` and the previous element of `nums[i]` is `nums[(i - 1 + n) % n]`.

A **subarray** may only include each element of the fixed buffer `nums` at most once. Formally, for a subarray `nums[i], nums[i + 1], ..., nums[j]`, there does not exist `i <= k1`, `k2 <= j` with `k1 % n == k2 % n`.

</aside>
*/

int maxSubarraySumCircular(vector<int>& nums) {
    int max_sum=INT_MIN,min_sum=INT_MAX;
    int curr_max=0,curr_min=0,total=0;
    for(auto it:nums){
        curr_max=max(it,it+curr_max);
        max_sum=max(curr_max,max_sum);
        total+=it;
    }
    for(auto it:nums){
        curr_min=min(it,it+curr_min);
         min_sum=min(curr_min,min_sum);
    }
    if(max_sum>0){
        if(total-min_sum>max_sum){
            max_sum=total-min_sum;
            return max_sum;
         }
        }
        return max_sum;
}


/*
<aside>
💡 **Question 3**

The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers `0` and `1` respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a **stack**. At each step:

- If the student at the front of the queue **prefers** the sandwich on the top of the stack, they will **take it** and leave the queue.
- Otherwise, they will **leave it** and go to the queue's end.

This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays `students` and `sandwiches` where `sandwiches[i]` is the type of the `ith` sandwich in the stack (`i = 0` is the top of the stack) and `students[j]` is the preference of the `jth` student in the initial queue (`j = 0` is the front of the queue). Return *the number of students that are unable to eat.*

</aside>
*/

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int>q;
    for(int i=0;i<students.size();i++)
    q.push(students[i]);
    int count = 0;
    int index = 0;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        if(curr == sandwiches[index])
            {
                count = 0;
                index++;
            }
        else {

                count++ ;
                q.push(curr);
            }
            
        if(count == q.size())
            break;
    }
         return q.size();
}



/*
<aside>
💡 **Question 4**

You have a `RecentCounter` class which counts the number of recent requests within a certain time frame.

Implement the `RecentCounter` class:

- `RecentCounter()` Initializes the counter with zero recent requests.
- `int ping(int t)` Adds a new request at time `t`, where `t` represents some time in milliseconds, and returns the number of requests that has happened in the past `3000` milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range `[t - 3000, t]`.

It is **guaranteed** that every call to `ping` uses a strictly larger value of `t` than the previous call.

</aside>
*/
class RecentCounter {
private:
    queue<int>data;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        data.push(t);
        while(data.front()<t-3000){
            data.pop();
        }
        return data.size();
        
    }
}; 

/*
<aside>
💡 **Question 5**

There are `n` friends that are playing a game. The friends are sitting in a circle and are numbered from `1` to `n` in **clockwise order**. More formally, moving clockwise from the `ith` friend brings you to the `(i+1)th` friend for `1 <= i < n`, and moving clockwise from the `nth` friend brings you to the `1st` friend.

The rules of the game are as follows:

1. **Start** at the `1st` friend.
2. Count the next `k` friends in the clockwise direction **including** the friend you started at. The counting wraps around the circle and may count some friends more than once.
3. The last friend you counted leaves the circle and loses the game.
4. If there is still more than one friend in the circle, go back to step `2` **starting** from the friend **immediately clockwise** of the friend who just lost and repeat.
5. Else, the last friend in the circle wins the game.

Given the number of friends, `n`, and an integer `k`, return *the winner of the game*

</aside>
*/

int findTheWinner(int n, int k) {
	queue<int> q;
	for (int i = 1; i <= n; i++)
		q.push(i);
	while (q.size() > 1) {
		for (int i = 1; i < k; i++) {
			q.push(q.front());
			q.pop();
		}
		q.pop();
	}
	return q.front();
}


/*
<aside>
💡 **Question 6**

You are given an integer array `deck`. There is a deck of cards where every card has a unique integer. The integer on the `ith` card is `deck[i]`.

You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.

You will do the following steps repeatedly until all cards are revealed:

1. Take the top card of the deck, reveal it, and take it out of the deck.
2. If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
3. If there are still unrevealed cards, go back to step 1. Otherwise, stop.

Return *an ordering of the deck that would reveal the cards in increasing order*.

**Note** that the first entry in the answer is considered to be the top of the deck.

</aside>
*/
vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    int n = deck.size();
    queue<int> q;
    for (int i = 0; i < n; i++)
        q.push(i);
    vector<int> v(n);
    int k = 0;
    sort(deck.begin(), deck.end());

    while (!q.empty())
    {
        v[q.front()] = deck[k];
        q.pop();
        k++;
        if (!q.empty())
        {
            q.push(q.front());
            q.pop();
        }
    }
    return v;
}


/*
<aside>
💡 **Question 7**

Design a queue that supports `push` and `pop` operations in the front, middle, and back.

Implement the `FrontMiddleBack` class:

- `FrontMiddleBack()` Initializes the queue.
- `void pushFront(int val)` Adds `val` to the **front** of the queue.
- `void pushMiddle(int val)` Adds `val` to the **middle** of the queue.
- `void pushBack(int val)` Adds `val` to the **back** of the queue.
- `int popFront()` Removes the **front** element of the queue and returns it. If the queue is empty, return `1`.
- `int popMiddle()` Removes the **middle** element of the queue and returns it. If the queue is empty, return `1`.
- `int popBack()` Removes the **back** element of the queue and returns it. If the queue is empty, return `1`.

**Notice** that when there are **two** middle position choices, the operation is performed on the **frontmost** middle position choice. For example:

- Pushing `6` into the middle of `[1, 2, 3, 4, 5]` results in `[1, 2, 6, 3, 4, 5]`.
- Popping the middle from `[1, 2, 3, 4, 5, 6]` returns `3` and results in `[1, 2, 4, 5, 6]`.
</aside>
*/

class Node{
    public:
    int data;
    Node* next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
class FrontMiddleBackQueue {
public:
    Node* root;
    FrontMiddleBackQueue() {
        root=NULL;
    }
    
    void pushFront(int val) {
        if(root==NULL)
        {
            root=new Node(val);
        }
        else
        {
            Node* temp=new Node(val);
            temp->next=root;
            root=temp;
        }
    }
    
    void pushMiddle(int val) {
        if(root==NULL)
        {
            root=new Node(val);
        }
        else if(root->next==NULL)
        {
            Node* temp=new Node(val);
            temp->next=root;
            root=temp;
        }
        else
        {
            Node* fast=root;
            Node* slow=root;
            while(fast!=NULL and fast->next!=NULL)
            {
                fast=fast->next->next;
                if(fast!=NULL and fast->next!=NULL)
                {
                    slow=slow->next;
                }
            }
            Node* temp=slow->next;
            Node* t=new Node(val);
            slow->next=t;
            t->next=temp;
        }
    }
    
    void pushBack(int val) {
        Node* temp=root;
        if(root==NULL)
        {
            root=new Node(val);
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=new Node(val);
        }
    }
    
    int popFront() {
        if(root==NULL)
        {
            return -1;
        }
        int ans=root->data;
        root=root->next;
        return ans;
    }
    
    int popMiddle() {
        if(root==NULL)
        {
            return -1;
        }
        if(root->next==NULL or root->next->next==NULL)
        {
            int ans=root->data;
            root=root->next;
            return ans;
        }
        Node* fast=root;
        Node* slow=root;
        while(fast!=NULL and fast->next!=NULL)
        {
            fast=fast->next->next;
            if(fast!=NULL and fast->next!=NULL and fast->next->next!=NULL)
            {
                slow=slow->next;
            }
        }
        int ans=slow->next->data;
        slow->next=slow->next->next;
        return ans;
    }
    
    int popBack() {
        Node* temp=root;
        if(root==NULL)
        {
            return -1;
        }
        if(root->next==NULL)
        {
            int ans=root->data;
            root=NULL;
            return ans;
        }
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        int ans=temp->next->data;
        temp->next=NULL;
        return ans;
    }
};


/*

<aside>
💡 **Question 8**

For a stream of integers, implement a data structure that checks if the last `k` integers parsed in the stream are **equal** to `value`.

Implement the **DataStream** class:

- `DataStream(int value, int k)` Initializes the object with an empty integer stream and the two integers `value` and `k`.
- `boolean consec(int num)` Adds `num` to the stream of integers. Returns `true` if the last `k` integers are equal to `value`, and `false` otherwise. If there are less than `k` integers, the condition does not hold true, so returns `false`.
</aside>
*/

class DataStream {
public:
    
    queue<int> que;
    int val,K;
    
    DataStream(int value, int k) {
        val = value;
        K = k;
    }
    
    bool consec(int num) {
        if(num == val) que.push(val);
        else {que = decltype(que){};}
        
        int sz = que.size(),k = K;
        
        if(sz < k){return 0;}
      
        return 1;
    }
};