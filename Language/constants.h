#ifndef CONSTANT_H
#define CONSTANT_H

namespace Constants
{
// clang-format off
static constexpr const char * const UNKNOWN     = "Unknown";
static constexpr const char * const IDENTIFIER  = "Identifier";
static constexpr const char * const END_OF_FILE = "eof";

static constexpr const char * const PLUS   = "+";
static constexpr const char * const MINUS  = "-";
static constexpr const char * const ASSIGN = "=";

static constexpr const char * const EQUAL         = "==";
static constexpr const char * const NOT_EQUAL     = "!=";
static constexpr const char * const NOT           = "!";
static constexpr const char * const GREATER_THEN  = ">";
static constexpr const char * const LESS_THEN     = "<";
static constexpr const char * const GREATER_EQUAL = ">=";
static constexpr const char * const LESS_EQUAL    = "<=";

static constexpr const char * const COMMA     = ",";
static constexpr const char * const SEMICOLON = ";";

static constexpr const char * const LEFT_PARENT  = "(";
static constexpr const char * const RIGHT_PARENT = ")";
static constexpr const char * const LEFT_BRACE   = "{";
static constexpr const char * const RIGHT_BRACE  = "}";

static constexpr const char * const LET    = "let";
static constexpr const char * const FUNC   = "func";
static constexpr const char * const IF     = "if";
static constexpr const char * const RETURN = "return";
static constexpr const char * const ELSE   = "else";
// clang-format on
}

#endif // CONSTANT_H
