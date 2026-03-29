#include <iostream>
using namespace std;

class User; // forward declaration

class Comment {
    int commentid;
    string content;
    User* author;
    static int nextCommentid;
public:
    Comment() {}
    Comment(string c, User* a) {
        content = c;
        author = a;
        commentid = nextCommentid++;
    }
    void displayComment();
};

class Post {
    int postid;
    string content;
    Comment comments[10];
    int commentnum = 0;
    static int nextPostid;
public:
    Post() {}
    Post(string p) {
        content = p;
        postid = nextPostid++;
    }
    void displayComments() {
        for (int i = 0; i < commentnum; i++) {
            comments[i].displayComment();
        }
    }
    void displayPost() {
        cout << "ID: " << postid << "\nContent: " << content << "\nComments:";
        displayComments();
    }
    void AddComment(string c, User* a) {
        if (commentnum < 10) {
            comments[commentnum++] = Comment(c, a);
        }
    }
};

class User {
    int userid;
    string username;
    Post posts[10];
    int postnum = 0;
    static int nextUserid;
public:
    User() {}
    User(string n) {
        username = n;
        userid = nextUserid++;
    }
    void createPost(string p) {
        if (postnum < 10) {
            posts[postnum++] = Post(p);
        } else {
            cout << "post limit exceeded";
        }
    }
    void displayUserFeed() {
        for (int i = 0; i < postnum; i++) {
            posts[i].displayPost();
        }
    }
    string getName(); // declare here
};

// Implement methods after full class definition
string User::getName() {
    return username;
}

void Comment::displayComment() {
    cout << "\nAuthor: " << author->getName() << "\n" << content;
}

class socialMediaPlatform {
    User users[20];
public:
};

int Post::nextPostid = 1;
int User::nextUserid = 1;
int Comment::nextCommentid = 1;

int main() {
    User u1("Alice");
    u1.createPost("Hello World!");
    u1.createPost("Second Post");

    // Add a comment to first post
    u1.displayUserFeed();
    return 0;
}

