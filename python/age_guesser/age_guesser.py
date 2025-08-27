import random

class AgeGame:
    def __init__(self):
        self.minimum=15
        self.maximum=30
        self.tries=5
        self.guess=None
        self.name=""
        self.age=None
    def new_guess(self):
        """Function to generate the next guess within the current min/max inclusive."""
        self.guess = random.randint(self.minimum, self.maximum)
    def get_age(self):
        """Function to ask the users age until we get age in a valid range."""
        while True:
            try:
                self.age = int(input("Enter your age (15-30): "))
                if self.age == 69: print("Nice.")
                if 15 <= self.age <= 30:break #valid -> exit loop
                else:print("Invalid input. Age must be between 15 and 30.")
            except ValueError:
                print("Invalid input. Please enter a valid number.")
    def get_name(self):
        """Function to get the name of the user"""
        self.name = str(input("Please enter your name: ")).strip()
    def gorl(self):
        """Function to determine of guess is Greater than or Less than age"""
        pass
    def play(self):
        """Function to start playing"""
        for attempt in range(1, self.tries+1):
            self.new_guess()
            while True:
                try:
                    ans = str(input(f"Is your age {self.guess}? (y/n) ")).lower()
                    if ans in ("y","n"):break
                    else: print("Invalid input. Respond with 'Y' or 'N'.")
                except ValueError:print("Invalid input. Respond with 'Y' or 'N'.")
            if ans == "y":
                print(f"Victory!\n{self.name} is {self.guess} years old.\nGuessed in {attempt} tries.")
                return
            self.tries-=1
            while True:
                hint = input(f"\nIs your age higher (h) or lower (l) than that? (h/l) ").strip().lower()
                if hint in ("h","l"):break
                print("Invalid input. Respond with 'H' or 'L'.")
            if hint == "h":self.minimum=max(self.minimum,self.guess+1)
            else:self.maximum=min(self.maximum,self.guess-1)
        print(f"Out of tries! Your age is {self.age}. I'll get it next time, {self.name}.")


def main():
    game=AgeGame()
    game.get_name()
    game.get_age()
    game.play()

if __name__ == "__main__":
    main()
