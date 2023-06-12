import re
import subprocess

# Define the symbols to check
SYMBOLS = ["=", "&", "+", "|", "^", ","]
DEBUG = False
CHANGES = subprocess.check_output(["git", "diff", "--name-only", "HEAD~1", "HEAD"])
CHANGES = CHANGES.decode().splitlines()
    
def missing_space(line, index):
    # Two characters at the end of each lines
    if DEBUG:
        print(line)
    if(index == len(line)-2):
        if DEBUG:
            print("End of line")
            print("line[index] : ", line[index])
            print("line[index-1] : ", line[index-1])
            print("line[index+1] : ", line[index+1])
        missing_space = line[index] == "+" and line[index-1] != "+" \
                     or line[index] != "+" and line[index] != "," and line[index-1] != " "
    elif(index == line[0]):
        if DEBUG:
            print("Beginning of line")
            print("line[index] : ", line[index])
            print("line[index-1] : ", line[index-1])
            print("line[index+1] : ", line[index+1])
        missing_space = line[index] == "+" and line[index+1] != "+" \
                     or line[index] != "+" and line[index+1] != " " 
    else :
        if DEBUG:
            print("Anywhere except corner cases")
            print("line[index] : ", line[index])
            print("line[index-1] : ", line[index-1])
            print("line[index+1] : ", line[index+1])
        missing_space = line[index] == "+" and (line[index+1] != "+" and line[index-1] != "+") \
                     or line[index] == "," and line[index+1] != " " \
                     or not(line[index] == "=" and line[index-1] == "<") \
                     or line[index] != "+" and line[index] != "," and (line[index+1] != " " or line[index-1] != " ") \
                        and (line[index] != "=" and line[index-1] != "<")    
    return missing_space

# Run the script on all relevant files
# for file in CHANGES:
fail = False
for file in CHANGES:
    filename = file.split("/")[-1]
    extension = filename.split(".")[-1]
    if extension == "sv":
        with open(file, "r") as f:
            lines = f.readlines()
        for line_num, line in enumerate(lines, start=1):
            for symbol in SYMBOLS:
                index = line.find(symbol)
                while(index >= 0):
                    if DEBUG:
                        print(symbol)
                    if missing_space(line, index) :
                        print(f"Missing space at ligne {line_num} after \"{line[index]}\"\n{line}")
                        fail |= True
                    index = line.find(symbol, index + 1)
if(fail):
    if DEBUG:
        print("failure")
    exit(1)