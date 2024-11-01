# Twitter Class - Design and Implementation

This README provides an overview of a simplified `Twitter` class design, simulating core functionalities of Twitter. The implemented class allows users to post tweets, follow and unfollow other users, and view a personalized news feed of the latest tweets.

## Table of Contents

- [Twitter Class - Design and Implementation](#twitter-class---design-and-implementation)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Class Definition](#class-definition)
    - [Code Breakdown](#code-breakdown)
    - [Explanation of Core Components](#explanation-of-core-components)
  - [Data Members](#data-members)
  - [Public Methods](#public-methods)
    - [1. `postTweet`](#1-posttweet)
    - [2. `getNewsFeed`](#2-getnewsfeed)
    - [3. `follow`](#3-follow)
    - [4. `unfollow`](#4-unfollow)
  - [Usage Example](#usage-example)
  - [Constraints](#constraints)
  - [Complexity Analysis](#complexity-analysis)
  - [Other Solutions](#other-solutions)
    - [Solution - 1](#solution---1)
    - [Solution - 2](#solution---2)
    - [Solution - 3](#solution---3)

---

## Overview

The `Twitter` class offers the following functionalities:

1. **Tweet Posting**: Users can post unique tweets identified by a unique `tweetId`.
2. **News Feed Retrieval**: Each user can view the 10 most recent tweets from users they follow or from themselves.
3. **Follow/Unfollow**: Users can follow or unfollow other users, influencing the tweets that appear in their news feed.

This class is intended for a compact, efficient representation of a simplified Twitter feed with limited follow, tweet, and news feed functionalities.

---

## Class Definition

```cpp
class Twitter {
public:
    Twitter(); // Constructor
    void postTweet(int userId, int tweetId);
    std::vector<int> getNewsFeed(int userId);
    void follow(int followerId, int followeeId);
    void unfollow(int followerId, int followeeId);

private:
    std::map<int, std::set<int>> friends; // Stores followers/followees
    int currentTime;                      // Tracks tweet order
    std::priority_queue<std::vector<int>> timeline; // Stores tweets in reverse order of posting time
};
```

---

The `Twitter` class implementation here creates a simplified model of Twitter, allowing users to post tweets, follow/unfollow others, and retrieve the 10 most recent tweets in their news feed. Let's walk through each component of this implementation.

### Code Breakdown

```cpp
#include <vector>
#include <map>
#include <set>
#include <queue>

class Twitter {
public:
    // Data structures to store friendships and tweets.
    std::map<int, std::set<int>> friends;      // Follower-followee relationships
    int currentTime = 0;                       // Timestamp to maintain tweet order
    std::priority_queue<std::vector<int>> timeline;  // Global timeline of tweets sorted by timestamp

    // Constructor: Initializes Twitter object with default values
    Twitter() {
        friends.clear();                           // Clear any existing friendships
        currentTime = 0;                           // Initialize time
        timeline = std::priority_queue<std::vector<int>>(); // Initialize empty timeline
    }

    // Method to post a new tweet
    void postTweet(int userId, int tweetId) {
        // Each tweet is pushed onto the timeline with the timestamp, tweetId, and userId
        timeline.push({currentTime++, tweetId, userId});
    }

    // Method to retrieve the top 10 most recent tweets in the user's news feed
    std::vector<int> getNewsFeed(int userId) {
        std::vector<int> topTenTweets;             // Stores the top 10 tweet IDs for the feed
        int countTweets = 0;                       // Counter for the number of tweets in the feed

        // Make a copy of the timeline to avoid modifying the original tweet order
        std::priority_queue<std::vector<int>> userTimeline = timeline;

        // Extract tweets until we have 10 or the timeline is empty
        while (!userTimeline.empty() && countTweets < 10) {
            auto recentTweet = userTimeline.top();   // Get the most recent tweet
            userTimeline.pop();

            // Check if the tweet belongs to the user or a followee of the user
            if (recentTweet[2] == userId || friends[userId].count(recentTweet[2])) {
                topTenTweets.push_back(recentTweet[1]);  // Add the tweet ID to the feed
                countTweets++;
            }
        }

        return topTenTweets;
    }

    // Method for a user to follow another user
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);     // Adds the followeeId to the follower's friend list
    }

    // Method for a user to unfollow another user
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);      // Removes the followeeId from the follower's friend list
    }
};
```

### Explanation of Core Components

1. **Data Members**:

   - **`friends`**: Stores follow relationships in a map, with each user ID pointing to a set of user IDs they are following.
   - **`currentTime`**: Ensures each tweet has a unique timestamp, helping sort tweets by recency.
   - **`timeline`**: A max-heap (`priority_queue`) holding each tweet in the form of a vector `[timestamp, tweetId, userId]` to keep all tweets in sorted order.

2. **Methods**:
   - **`postTweet(int userId, int tweetId)`**:
     - Inserts a tweet into the `timeline`, using `currentTime` as the timestamp, and increments `currentTime`.
   - **`getNewsFeed(int userId)`**:
     - Retrieves the 10 most recent tweets from the user and their followees by making a copy of `timeline` and filtering tweets from followees and the user.
   - **`follow(int followerId, int followeeId)`**:
     - Adds the followee to the follower’s `friends` set, allowing the follower to view tweets from this followee.
   - **`unfollow(int followerId, int followeeId)`**:
     - Removes the followee from the follower’s `friends` set, removing the followee's tweets from the follower’s news feed.

## Data Members

- **`friends`**: A `map` where each `userId` maps to a `set` of followees (`followeeId`s). This structure enables efficient following/unfollowing and quick access to the followees of any user.
- **`currentTime`**: An integer to uniquely timestamp each tweet, ensuring tweets are ordered correctly in the feed.
- **`timeline`**: A `priority_queue` (max-heap) storing all tweets as `[time, tweetId, userId]` for global tweet tracking, enabling retrieval of the latest tweets efficiently.

---

## Public Methods

### 1. `postTweet`

```cpp
void postTweet(int userId, int tweetId);
```

- **Description**: Composes a new tweet by a user with `userId`. Each tweet has a unique `tweetId` and a timestamp (using `currentTime`), which is incremented with each tweet.
- **Parameters**:
  - `userId`: ID of the user posting the tweet.
  - `tweetId`: Unique ID of the tweet being posted.
- **Returns**: Nothing.

### 2. `getNewsFeed`

```cpp
std::vector<int> getNewsFeed(int userId);
```

- **Description**: Retrieves up to 10 of the most recent tweet IDs in the user’s news feed. The news feed contains tweets from the user’s followees and the user’s own tweets, sorted from most recent to least recent.
- **Parameters**:
  - `userId`: ID of the user whose news feed is being fetched.
- **Returns**: A vector of up to 10 `tweetId`s, ordered by recency.

### 3. `follow`

```cpp
void follow(int followerId, int followeeId);
```

- **Description**: Allows a user with `followerId` to follow another user with `followeeId`.
- **Parameters**:
  - `followerId`: ID of the user who will follow.
  - `followeeId`: ID of the user being followed.
- **Returns**: Nothing.

### 4. `unfollow`

```cpp
void unfollow(int followerId, int followeeId);
```

- **Description**: Allows a user with `followerId` to unfollow another user with `followeeId`.
- **Parameters**:
  - `followerId`: ID of the user who will unfollow.
  - `followeeId`: ID of the user being unfollowed.
- **Returns**: Nothing.

---

## Usage Example

Here is a usage example with the `Twitter` class:

```cpp
Twitter twitter;

// User 1 posts a new tweet with ID 5
twitter.postTweet(1, 5);

// User 1’s news feed returns [5]
std::vector<int> feed = twitter.getNewsFeed(1); // Returns [5]

// User 1 follows User 2
twitter.follow(1, 2);

// User 2 posts a new tweet with ID 6
twitter.postTweet(2, 6);

// User 1’s news feed now returns [6, 5]
feed = twitter.getNewsFeed(1); // Returns [6, 5]

// User 1 unfollows User 2
twitter.unfollow(1, 2);

// User 1’s news feed returns [5]
feed = twitter.getNewsFeed(1); // Returns [5]
```

---

## Constraints

- User IDs and Tweet IDs range from `1` to `500`.
- All tweet IDs are unique.
- A maximum of `3 * 10^4` calls will be made to the methods `postTweet`, `getNewsFeed`, `follow`, and `unfollow`.

---

## Complexity Analysis

1. **Time Complexity**:

   - `postTweet`: \(O(\log N)\) due to inserting into the priority queue.
   - `getNewsFeed`: \(O(N \log K)\) where \(N\) is the number of tweets and \(K\) is the 10-tweet limit.
   - `follow` and `unfollow`: \(O(\log M)\), where \(M\) is the number of followees of the follower.

2. **Space Complexity**:
   - `O(T + U)` where \(T\) is the total number of tweets and \(U\) is the number of unique user-follow relationships.

---

This class offers a simplified yet efficient model of Twitter’s main features, supporting fast tweet posting, efficient feed generation, and streamlined follow/unfollow operations.

## Other Solutions

### Solution - 1

```cpp
class Twitter
{
private:
  map<int, set<int>> following;
  vector<pair<int, int>> posts;

public:
  Twitter()
  {
  }

  void postTweet(int userId, int tweetId)
  {
    posts.push_back({userId, tweetId});
  }

  vector<int> getNewsFeed(int userId)
  {
    vector<int> feed;
    int index = posts.size() - 1;
    cout << "fetching for " << userId << " from " << index << endl;
    while (feed.size() < 10 && index > -1)
    {
      cout << "processing " << posts[index].first << " " << posts[index].second << endl;

      if (posts[index].first == userId || following[userId].find(posts[index].first) != following[userId].end())
        feed.push_back(posts[index].second);
      index--;
    }
    return feed;
  }

  void follow(int followerId, int followeeId)
  {
    following[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId)
  {
    following[followerId].erase(followeeId);
  }
};
```

### Solution - 2

```java
public class Twitter {
  private static int timeStamp = 0;

  // easy to find if user exist
  private Map<Integer, User> userMap;

  // Tweet link to next Tweet so that we can save a lot of time
  // when we execute getNewsFeed(userId)
  private class Tweet {
    public int id;
    public int time;
    public Tweet next;

    public Tweet(int id) {
      this.id = id;
      time = timeStamp++;
      next = null;
    }
  }

  // OO design so User can follow, unfollow and post itself
  public class User {
    public int id;
    public Set<Integer> followed;
    public Tweet tweet_head;

    public User(int id) {
      this.id = id;
      followed = new HashSet<>();
      follow(id); // first follow itself
      tweet_head = null;
    }

    public void follow(int id) {
      followed.add(id);
    }

    public void unfollow(int id) {
      followed.remove(id);
    }

    // everytime user post a new tweet, add it to the head of tweet list.
    public void post(int id) {
      Tweet t = new Tweet(id);
      t.next = tweet_head;
      tweet_head = t;
    }
  }

  /** Initialize your data structure here. */
  public Twitter() {
    userMap = new HashMap<Integer, User>();
  }

  /** Compose a new tweet. */
  public void postTweet(int userId, int tweetId) {
    if (!userMap.containsKey(userId)) {
      User u = new User(userId);
      userMap.put(userId, u);
    }
    userMap.get(userId).post(tweetId);

  }

  // Best part of this.
  // first get all tweets lists from one user including itself and all people it
  // followed.
  // Second add all heads into a max heap. Every time we poll a tweet with
  // largest time stamp from the heap, then we add its next tweet into the heap.
  // So after adding all heads we only need to add 9 tweets at most into this
  // heap before we get the 10 most recent tweet.
  public List<Integer> getNewsFeed(int userId) {
    List<Integer> res = new LinkedList<>();

    if (!userMap.containsKey(userId))
      return res;

    Set<Integer> users = userMap.get(userId).followed;
    PriorityQueue<Tweet> q = new PriorityQueue<Tweet>(users.size(), (a, b) -> (b.time - a.time));
    for (int user : users) {
      Tweet t = userMap.get(user).tweet_head;
      // very imporant! If we add null to the head we are screwed.
      if (t != null) {
        q.add(t);
      }
    }
    int n = 0;
    while (!q.isEmpty() && n < 10) {
      Tweet t = q.poll();
      res.add(t.id);
      n++;
      if (t.next != null)
        q.add(t.next);
    }

    return res;

  }

  /**
   * Follower follows a followee. If the operation is invalid, it should be a
   * no-op.
   */
  public void follow(int followerId, int followeeId) {
    if (!userMap.containsKey(followerId)) {
      User u = new User(followerId);
      userMap.put(followerId, u);
    }
    if (!userMap.containsKey(followeeId)) {
      User u = new User(followeeId);
      userMap.put(followeeId, u);
    }
    userMap.get(followerId).follow(followeeId);
  }

  /**
   * Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op.
   */
  public void unfollow(int followerId, int followeeId) {
    if (!userMap.containsKey(followerId) || followerId == followeeId)
      return;
    userMap.get(followerId).unfollow(followeeId);
  }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
```

### Solution - 3

```cpp
class Twitter
{
private:
  unordered_map<int, set<int>> fo;
  unordered_map<int, vector<pair<int, int>>> t;
  long long time;

public:
  /** Initialize your data structure here. */
  Twitter()
  {
    time = 0;
  }

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId)
  {
    t[userId].push_back({time++, tweetId});
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId)
  {
    priority_queue<pair<int, int>> maxHeap;
    for (auto it = t[userId].begin(); it != t[userId].end(); ++it)
      maxHeap.push(*it);
    for (auto it1 = fo[userId].begin(); it1 != fo[userId].end(); ++it1)
    {
      int usr = *it1; // get target user
      for (auto it2 = t[usr].begin(); it2 != t[usr].end(); ++it2)
        maxHeap.push(*it2);
    }
    vector<int> res;
    while (maxHeap.size() > 0)
    {
      res.push_back(maxHeap.top().second);
      if (res.size() == 10)
        break;
      maxHeap.pop();
    }
    return res;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
  void follow(int followerId, int followeeId)
  {
    if (followerId != followeeId)
      fo[followerId].insert(followeeId);
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
  void unfollow(int followerId, int followeeId)
  {
    fo[followerId].erase(followeeId);
  }
};
```
