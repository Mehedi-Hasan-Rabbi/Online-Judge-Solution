class FoodRatings {
public:
    // If want you can use unordered_map
    map<string, pair<string, int>> food_list;
    map<string, set<pair<int, string>>> cuisines_list;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = (int) foods.size();
        
        for (int i = 0; i < n; i++) {
            // food_list[ kimchi ] = < korean, 9 >
            food_list[foods[i]].first = cuisines[i];
            food_list[foods[i]].second = ratings[i];

            // cuisines_list[ japanese ] = [ <-14, ramen>, <-12, miso>, <-8, sushi> ]
            cuisines_list[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisines_name = food_list[food].first;
        int oldRating = food_list[food].second;

        // Removing old data from cuisines_list
        cuisines_list[cuisines_name].erase({-oldRating, food});

        // Rating update
        food_list[food].second = newRating;

        // Insert new data into cuisines_list
        cuisines_list[cuisines_name].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return (*cuisines_list[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */