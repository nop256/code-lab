from datetime import datetime
import time, os


def trackProgress():
    """Tracks progress and stores it in a local text file."""
    scriptdir = os.path.dirname(os.path.abspath(__file__)) #retrieving the absolute path of the directory the script is stored in
    #print(scriptDir) # for testing
    filename = os.path.join(scriptdir, "journal.md") #joining the absolute directory of script with filename
    
    #create the file if it doesn't exist
    if not os.path.exists(filename): #if filename does not exist in this scripts directory:
        with open(filename, "w", encoding="utf-8") as file: 
            file.write("CS-2450 Semester Journal\n") #writing the title of the file
        
    #prompt user for today's progress
    print("\nWhat entry would you like to log today?") #instruction
    progress_entry = input(">>> ").strip() #prompts the user for their daily progress update

    #capture timestamp
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S") #Year-Month-Day Hour:Minute:Second

    with open(filename, "a", encoding="utf-8") as file: #utf encoding circumvents bugs I was having
        file.write("="*40 + "\n") #write a line break using equals sign
        file.write(f"Date: {timestamp}\n") #record the current date and timestamp
        file.write(f"Subject: {progress_entry}\n\n") #record the user's daily progress input from above

    print("✅ Journal logged successfully!") #report log was recorded successfully
    
if __name__ == "__main__":
    trackProgress()

