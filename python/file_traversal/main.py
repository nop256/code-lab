import time
from student import Student
#from bag import Bag
from linkedlist import Bag

def main():
    """Reads FakeNames.txt, inserts students into a Bag, and times the process."""
    b = Bag()

    
    print(f"\nInserting...")
    t1 = time.time()
    try:                
        with open("FakeNames.txt", "r") as f:
            for line in f:
                words = line.strip().split()
                last, first, ss, email, age = words
                student = Student(last, first, ss, email, age)
                if not b.insert(student):
                    print(f"Duplicate detected: {student}")

    except FileNotFoundError:
        print("Error: FakeNames.txt not found. Make sure the file is in the correct directory.")
        return
    f.close()
    t2 = time.time()
    print(f"Time taken to insert students: {t2 - t1:.4f} seconds")
    print(f"Total students added: {b.size()}\n")
    
    
    # Iterate through all students in the Bag and calculate average age to 4 digits
    print(f"Traversing...")
    t3 = time.time()
    total_age = 0
    count_students = 0
    for student in b:
        total_age += int(student.age)
        count_students += 1
    avg_age = total_age / count_students
    t4 = time.time()
    if count_students > 0:
        print(f"Average student age: {avg_age:.2f}")
    else: print(f"No students to calculate age.")
    print(f"Time taken to calculate average age: {t4 - t3:.4f} seconds\n")
        
    
    # Delete all students from DeleteNames.txt
    print(f"Deleting...")
    t5=time.time()
    try:
        with open("DeleteNames.txt", "r") as d:
            for line in d:
                ssn = line.strip()
                student_to_delete = Student("","",ssn,"","")
                if not b.delete(student_to_delete):
                    print(f"SSN not found for deletion: {ssn}")
                    
    except FileNotFoundError:
        print("Error: DeleteNames.txt not found. Make sure the file is in the correct directory.")
        return
    d.close()
    t6 = time.time()
    print(f"Time taken to delete students: {t6-t5:.4f} seconds\n")
    
    
    # Retrieve students listed in RetrieveNames.txt
    print(f"Retrieving...")
    t7 = time.time()
    total_age_retrieved = 0
    count_retrieved = 0
    try:
        with open("RetrieveNames.txt", "r") as r:
            for line in r:
                ssn = line.strip()
                student_to_retrieve = Student("","",ssn,"","")
                retrieved = b.retrieve(student_to_retrieve)
                if retrieved:
                    total_age_retrieved += int(retrieved.age)
                    count_retrieved += 1
                else:
                    print(f"SSN not found for retrieval: {ssn}")
                    
    except FileNotFoundError:
        print("Error: RetrieveNames.txt not found. Make sure the file is in the correct directory.")
        return
    r.close()
    t8 = time.time()
    
    if count_retrieved > 0:
        avg_age_retrieved = total_age_retrieved / count_retrieved
        print(f"Average age of retrieved students: {avg_age_retrieved}")
    else:
        print("No students retrieved.")
    
    print(f"Time taken to retrieve students: {t8 - t7:.4f}\n")
    
    print("Done.")
    

if __name__ == "__main__":
    main()
