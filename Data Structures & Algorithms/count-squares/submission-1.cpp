class CountSquares {
public:

    map<pair<int,int>, int> mp;

    CountSquares() {

    }

    void add(vector<int> point) {

        mp[{point[0], point[1]}]++;
    }

    int count(vector<int> point) {

        int x = point[0];
        int y = point[1];

        int ans = 0;

        for (auto &it : mp) {

            int nx = it.first.first;
            int ny = it.first.second;

            // diagonal condition
            if (abs(nx - x) != abs(ny - y) ||
                nx == x ||
                ny == y) {

                continue;
            }

            ans +=
                mp[{nx, ny}] *
                mp[{x, ny}] *
                mp[{nx, y}];
        }

        return ans;
    }
};