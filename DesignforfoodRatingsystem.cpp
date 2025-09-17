class FoodRatings {
private: 
    unordered_map<string,string> foodToCuisines;
    unordered_map<string,int> foodToRating;
    unordered_map<string,set<pair<int,string>>> cuisineTofood;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            string food=foods[i];
            string cuisine=cuisines[i];
            int rating=ratings[i];
            foodToCuisines[food]=cuisine;
            foodToRating[food]=rating;
            cuisineTofood[cuisine].insert({-rating,food});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine=foodToCuisines[food];
        int oldrating=foodToRating[food];

        cuisineTofood[cuisine].erase({-oldrating,food});

        foodToRating[food]=newRating;

        cuisineTofood[cuisine].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        return cuisineTofood[cuisine].begin()->second;
    }
};
