// DELETE NODES FORM LINKED LIST PRESENT IN ARRAY

/*
You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.

Example 1:

Input: nums = [1,2,3], head = [1,2,3,4,5]

Output: [4,5]

Explanation:

Remove the nodes with values 1, 2, and 3.

Example 2:

Input: nums = [1], head = [1,2,1,2,1,2]

Output: [2,2,2]

Explanation:

Remove the nodes with value 1.

Example 3:

Input: nums = [5], head = [1,2,3,4]

Output: [1,2,3,4]

Explanation:

No node has value 5.

 

Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 105
    All elements in nums are unique.
    The number of nodes in the given list is in the range [1, 105].
    1 <= Node.val <= 105
    The input is generated such that there is at least one node in the linked list that has a value not present in nums.



*/



/* #include <unordered_set>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/

class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {

        std::unordered_set<int> nums_set(nums.begin(), nums.end());


        ListNode* prev = nullptr;
        ListNode* current = head;


        while (current != nullptr) {

            if (nums_set.find(current->val) != nums_set.end()) {
                if (prev == nullptr) {

                    head = current->next;
                } else {

                    prev->next = current->next;
                }

                ListNode* toDelete = current;
                current = current->next;
                delete toDelete;
            } else {

                prev = current;
                current = current->next;
            }
        }

        return head;
    }
};
