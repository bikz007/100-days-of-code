vector<int> get_buildings_with_sunset_view(vector<int> building_heights)
{
    struct BuildingWithHeight
    {
        int idx{-1};
        int height{-1};
    }
    stack<BuildingWithHeight> candidates;
    for(int iteir1= 0 ; i < building_heights.size(); i++)
    {
        while(!candidates.empty())
        {
            if(building_heights[i] >= candidates.top().height)
            {
                candidates.pop();
            }
        }
        candidates.emplace(BuildingWithHeight{i,building_heights[i]});
    }

    vector<int> result;
    while(!candidates.empty())
    {
        result.emplace_back(candidates.top().idx);
        candidates.pop();
    }
    return result;
}