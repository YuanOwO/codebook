vector<int>virTree(vector<int> ver) {
    sort(ver.begin(),ver.end(),cmp); //用dfn排序
    vector<int>res(ver.begin(),ver.end());
    for(int i=1;i<ver.size();i++){
         res.push_back(lca(ver[i-1],ver[i]));//把LCA丟進虛樹內   
    }
    sort(res.begin(),res.end(),cmp);//在用dfn排序
    res.erase(unique(res.begin(),res.end()), res.end());//可能會有重複的點，需要去掉重複的
    return res;
}
int count_answer(vector<int>virTree){
    sort(virTree.begin(),virTree.end(),cmp);
    int ans=0;
    for(int i=1;i<virTree.size();i++){
        ans+=query(lca(virTree[i-1],virTree[i]),virTree[i]);
    }
    return ans;
}