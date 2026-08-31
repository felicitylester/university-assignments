# nameReverse.asm
# Write a program in MIPS32 Assembly Language to prompt the user for a name 
# in the format "FirstName LastName", and print that name to the console reversed. 
#
# prompt user to enter input
# program output
#

.data
prompt: .asciiz "Enter your name (FIRST LAST): "
output: .asciiz " reversed is "
newline: .asciiz "\n"
space: .asciiz " "
buffer: .space 50  # space for user input
msg: .asciiz "Program is finished running --"

.text	# says rest is instructions
.globl main	# like global


main:
#display the open prompt to the user
	li $v0, 4	#li = load immediate
	la $a0, prompt
	syscall
	
#read user input into buffer
	li $v0, 8
	la $a0, buffer
	li $a1, 50
	syscall

# print user input label
	li $v0, 4
	la $a0, buffer
	syscall

# print user input
	li $v0, 4
	la $a0, buffer
	syscall

# print " reversed is " label
	li $v0, 4
	la $a0, output
	syscall
	
# reverse and print the name
	li $t2, 0
	
strLen: #getting length of string
	lb $t0, buffer($t2)	#loading value
	add $t2, $t2, 1
	beqz $t0, strLen	#branh if equal
	sub $t2, $t2, 1

Loop:
    lb $t1, buffer($t2)   # Load the character from the buffer into $t1
    beqz $t1, print_newline  # Check if the character is zero (end of string)
    addi $t2, $t2, 1
    li $v0, 11
    lb $a0, buffer($t2)
    syscall
    j Loop   # Jump back to the start of the loop unconditionally
    
print_newline:	# print newline
	li $v0, 4
	la $a0, newline
	syscall

# prints " program is finished running --" message
	li $v0, 4
	la $a0, msg
	syscall
	
# how to exit program
	li $v0, 10
	syscall
