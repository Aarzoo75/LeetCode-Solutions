class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode* newnode=new ListNode();
        ListNode* Node=newnode;
        priority_queue<vector<int>>q;
        for(int i=0;i<lists.size();i++){
            ListNode* node=lists[i];
            if (node!=NULL){
            q.push({-1*node->val,0,i});
        }}
        vector<int>ans;
        while (q.size()){
            vector<int>vec=q.top();q.pop();
            newnode->next=new ListNode(-1*vec[0]);
            newnode=newnode->next;
            ListNode* nxt=lists[vec[2]];
            if (nxt->next!=NULL){
                nxt=nxt->next;
                lists[vec[2]]=nxt;
                q.push({-1*nxt->val,vec[1]+1,vec[2]});
                
        }}
        return Node->next;
    }
};