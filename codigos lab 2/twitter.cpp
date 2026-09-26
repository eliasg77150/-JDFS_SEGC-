#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

// LeetCode 355 - Design Twitter
class Twitter {
public:
    Twitter() : timestamp(0) {}

    void postTweet(int userId, int tweetId) {
        users[userId];
        tweetsByUser[userId].push_back({timestamp++, tweetId});
    }

    std::vector<int> getNewsFeed(int userId) {
        std::vector<std::pair<int,int>> candidates;

        auto addLastN = [&](int uid, int n) {
            auto it = tweetsByUser.find(uid);
            if (it == tweetsByUser.end()) return;
            const auto& v = it->second;
            int start = std::max(0, (int)v.size() - n);
            for (int i = (int)v.size() - 1; i >= start; --i) {
                candidates.push_back(v[i]);
            }
        };

        addLastN(userId, 10);
        auto it = users.find(userId);
        if (it != users.end()) {
            for (int followee : it->second) {
                addLastN(followee, 10);
            }
        }

        std::sort(candidates.begin(), candidates.end(),
                  [](const std::pair<int,int>& a, const std::pair<int,int>& b) {
                      return a.first > b.first;
                  });

        std::vector<int> result;
        for (int i = 0; i < (int)candidates.size() && i < 10; ++i) {
            result.push_back(candidates[i].second);
        }
        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        users[followerId].insert(followeeId);
        users[followeeId];
    }

    void unfollow(int followerId, int followeeId) {
        auto it = users.find(followerId);
        if (it != users.end()) {
            it->second.erase(followeeId);
        }
    }

private:
    int timestamp;
    std::unordered_map<int, std::unordered_set<int>> users;
    std::unordered_map<int, std::vector<std::pair<int,int>>> tweetsByUser;
};

void printFeed(const std::vector<int>& feed) {
    std::cout << "[";
    for (size_t i = 0; i < feed.size(); ++i) {
        std::cout << feed[i];
        if (i + 1 < feed.size()) std::cout << ", ";
    }
    std::cout << "]\n";
}

int main() {
    Twitter twitter;
    twitter.postTweet(1, 5);
    std::cout << "Feed usuario 1: ";
    printFeed(twitter.getNewsFeed(1)); // [5]

    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    std::cout << "Feed usuario 1 tras seguir a 2: ";
    printFeed(twitter.getNewsFeed(1)); // [6, 5]

    twitter.unfollow(1, 2);
    std::cout << "Feed usuario 1 tras dejar de seguir: ";
    printFeed(twitter.getNewsFeed(1)); // [5]
    return 0;
}
