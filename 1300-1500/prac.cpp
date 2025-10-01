
do{

    int mn = 1e9+10;
    for(int i=0;i<heights.size();i++)
    {
        if(heights.size()==1) mn = heights[i];
        if(i-1>=0&&heights[i]>heights[i-1])
            {
                mn = min(mn,heights[i]);
            }
            else if(i+1<heights[i].size()&&heights[i]<heights[i+1])
            {
                mn = min(mn,heights[i]);
            }
        
    }

    heights.erase(heights.find(mn));
    highlightOrder.push_back()

}   
while(highlight!=-1);