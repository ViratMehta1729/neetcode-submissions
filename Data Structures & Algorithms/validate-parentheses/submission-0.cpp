class Solution {
public:
    bool isValid(string s) 
    {
        string temp;
        for(auto x: s)
        {
            temp+=x;
            if(temp.size()>=2 && temp.substr(temp.size()-2, 2)=="()")
            {
                temp.pop_back();
                temp.pop_back();
            }

            if(temp.size()>=2 && temp.substr(temp.size()-2, 2)=="[]")
            {
                temp.pop_back();
                temp.pop_back();
            }

            if(temp.size()>=2 && temp.substr(temp.size()-2, 2)=="{}")
            {
                temp.pop_back();
                temp.pop_back();
            }
        }
        return temp.size()==0;
    }
};
