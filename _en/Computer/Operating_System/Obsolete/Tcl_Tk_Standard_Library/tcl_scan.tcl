set data "Name: John, Age: 25"
scan $data {Name: %[A-Za-z], Age: %d} name age
puts "Name: $name, Age: $age"
