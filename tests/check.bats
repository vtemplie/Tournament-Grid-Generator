tennis="tests/examples/tennis"
soccer="tests/examples/soccer"
compare="diff -ZB"

@test "Basic example runs with success" {
    run ./tournament < $tennis.in
    [ "$status" -eq 0 ]
}

@test "Wrong number of arguments" {
    run ./tournament -s < $tennis.in
    [ "$status" -eq 1 ]
    [ "$output" == "Error: wrong number of arguments" ]
}

@test "Short option for style is -s" {
    run ./tournament -s compact < $tennis.in
    [ "$status" -eq 0 ]
}

@test "Long option for format is --format" {
    run ./tournament --format id < $tennis.in
    [ "$status" -eq 0 ]
}

@test "Wrong option" {
    run ./tournament --sty compact < $tennis.in
    [ "$status" -eq 1 ]
    [ "$output" == "Error: unknown option (--sty)" ]
}

@test "Option recognition is case-sensitive" {
    run ./tournament --Style compact < $tennis.in
    [ "$status" -eq 1 ]
    [ "$output" == "Error: unknown option (--Style)" ]
}

@test "Wrong value for style" {
    run ./tournament --style compac < $tennis.in
    [ "$status" -eq 1 ]
    [ "$output" == "Error: unknown style (compac)" ]
}

@test "Wrong value for format" {
    run ./tournament --format ID < $tennis.in
    [ "$status" -eq 1 ]
    [ "$output" == "Error: unknown format (ID)" ]
}

@test "Tennis example with default options" {
    run $compare $tennis-default.out <(./tournament < $tennis.in)
    [ "$status" -eq 0 ]
}

@test "Soccer example with default options" {
    run $compare $soccer-default.out <(./tournament < $soccer.in)
    [ "$status" -eq 0 ]
}

@test "Tennis example with names" {
    run $compare $tennis-name.out <(./tournament -f name < $tennis.in)
    [ "$status" -eq 0 ]
}

@test "Tennis example with table" {
    run $compare $tennis-table.out <(./tournament -s table < $tennis.in)
    [ "$status" -eq 0 ]
}

@test "Tennis example with names in table" {
    run $compare $tennis-name-table.out <(./tournament -s table -f name < $tennis.in)
    [ "$status" -eq 0 ]
}

@test "Twenty players is ok" {
    head -n 20 $soccer-long.in | ./tournament
    [ "$?" -eq 0 ]
}

@test "Not enough players" {
    run ./tournament < $soccer-short.in
    [ "$output" == "Error: not enough players (minimum is 2)" ]
    [ "$status" -eq 1 ]
}

@test "Too many players" {
    run ./tournament < $soccer-long.in
    [ "$output" == "Error: too many players (maximum is 20)" ]
    [ "$status" -eq 1 ]
}

@test "Large table with id" {
    run $compare $soccer-long-table-id.out <(head -n 20 $soccer-long.in | ./tournament -s table)
    [ "$status" -eq 0 ]
}

@test "Large table with names" {
    run $compare $soccer-long-table-names.out <(head -n 20 $soccer-long.in | ./tournament -s table -f name)
    [ "$status" -eq 0 ]
}
