/*
bluepp
2017-01-02
May the force be with me!

https://leetcode.com/problems/design-twitter/

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.
Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
*/

class Twitter {

private:
    int cnt;
    unordered_map<int, set<int>> friends;
    unordered_map<int, map<int, int>> tweets;
    
public:
    /** Initialize your data structure here. */
    Twitter() {
        
        cnt = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        
        follow(userId, userId);
        tweets[userId].insert({cnt++, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        
        vector<int> res;
        map<int, int> top10;
        
      
        
        for (auto it : friends[userId])
        {
            for (auto p : tweets[it])
            {
                if (top10.size() > 0 && top10.begin()->first > p.first && top10.size() > 10) break;
                
                top10.insert({p.first, p.second});
                
                if (top10.size() > 10) 
                {
                    top10.erase(top10.begin());
                }
            }
        }
        
        
        
        
        for (auto it : top10)
        {
            res.push_back(it.second);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
        
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        
        friends[followerId].insert(followeeId);
        
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        
        if (followerId != followeeId)
        {
            friends[followerId].erase(followeeId);
        }
        
    }
};
