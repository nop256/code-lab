from flask import Flask, request, redirect, url_for, render_template

app = Flask(__name__)

# Temporary list to store names (clears when the server restarts)
names = []

# Home Page - Form to Enter Name
@app.route("/", methods=["GET"])
def index():
    return render_template("index.html")

# Submit Page - Adds Name to List
@app.route("/submit", methods=["POST"])
def submit():
    name = request.form.get("name")
    if name:  # Only add if name is not empty
        names.append(name)
    return redirect(url_for("index"))  # Redirect back to the form

# List Page - Show All Names
@app.route("/list")
def name_list():
    return render_template("list.html", names=names)

if __name__ == "__main__":
    app.run(debug=True)
