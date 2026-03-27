#include <iostream>
#include <string>
using namespace std;

// ------------------ Comment Class ------------------
class Comment {
    string content;
public:
    Comment(const string& _content) : content(_content) {}
    void editContent(const string& newContent) { content = newContent; }
    string getContent() const { return content; }
};

// ------------------ Post Class ------------------
class Post {
    string title;
    string content;
    Comment* comments[10]; // fixed-size array for simplicity
    int numComments;
public:
    Post(const string& _title, const string& _content)
        : title(_title), content(_content), numComments(0) {}

    void addComment(Comment* comment) {
        if (numComments < 10) comments[numComments++] = comment;
    }

    void removeComment(Comment* comment) {
        for (int i = 0; i < numComments; i++) {
            if (comments[i] == comment) {
                for (int j = i; j < numComments - 1; j++)
                    comments[j] = comments[j + 1];
                numComments--;
                break;
            }
        }
    }

    void displayInfo() const {
        cout << "Post: " << title << "\nContent: " << content << endl;
        cout << "Comments:" << endl;
        for (int i = 0; i < numComments; i++) {
            cout << "- " << comments[i]->getContent() << endl;
        }
        cout << endl;
    }
};

// ------------------ User Class ------------------
class User {
    string name;
    Post* posts[10]; // fixed-size array for simplicity
    int numPosts;
public:
    User(const string& _name) : name(_name), numPosts(0) {}

    Post* createPost(const string& title, const string& content) {
        if (numPosts < 10) {
            posts[numPosts] = new Post(title, content);
            return posts[numPosts++];
        }
        return nullptr;
    }

    void addCommentToPost(Post* post, Comment* comment) {
        post->addComment(comment);
    }

    void removeCommentFromPost(Post* post, Comment* comment) {
        post->removeComment(comment);
    }

    void displayUserPostsAndComments() const {
        cout << "User: " << name << endl;
        for (int i = 0; i < numPosts; i++) {
            posts[i]->displayInfo();
        }
    }
};

// ------------------ Main Scenario ------------------
int main() {
    User shafique("Shafique Rehman");

    // Create posts
    Post* vacation = shafique.createPost("My Vacation Adventure", "I had a great trip!");
    Post* dinner = shafique.createPost("Homemade Dinner", "Cooked something delicious!");

    // Add comments
    shafique.addCommentToPost(vacation, new Comment("Looks amazing!"));
    shafique.addCommentToPost(vacation, new Comment("I wish I could go there too"));

    Comment* recipeComment = new Comment("Yum, what's the recipe?");
    shafique.addCommentToPost(dinner, recipeComment);
    shafique.addCommentToPost(dinner, new Comment("Can I come over for dinner"));

    // Display before editing
    cout << "Before editing:\n";
    shafique.displayUserPostsAndComments();

    // Edit comment
    recipeComment->editContent("Yum, can you share the recipe?");

    // Display after editing
    cout << "\nAfter editing:\n";
    shafique.displayUserPostsAndComments();

    return 0;
}
