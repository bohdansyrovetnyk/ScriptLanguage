#include "gtest/gtest.h"

#include <memory>
#include <tuple>

#include "Language/lexer.h"
#include "Language/token.h"
#include "Language/constants.h"

struct ScriptData
{
    std::string rawScript;
    std::vector<Token> _expected;
};

class LexerTest : public ::testing::TestWithParam<ScriptData>
{
public:
    void SetUp() override
    {
        _lexer = std::make_unique<lexer::Lexer>();
    }

    void TearDown() override
    {
        _lexer.reset();
    }

protected:
    std::unique_ptr<lexer::Lexer> _lexer;
};


TEST_P(LexerTest, checkToken_allTokenParseCorrect)
{
    _lexer->setInput(GetParam().rawScript);

    for (const Token &token : GetParam()._expected)
    {
        Token currentToken = _lexer->nextToken();
        ASSERT_TRUE(currentToken.type() == token.type());
        ASSERT_TRUE(currentToken.literal() == token.literal());
    }
}

// clang-format off
INSTANTIATE_TEST_CASE_P(Script, LexerTest, ::testing::Values(
                            ScriptData{ "=(){},;", { Token(TokenType::Assign, Constants::ASSIGN),
                                                     Token(TokenType::LeftParent, Constants::LEFT_PARENT),
                                                     Token(TokenType::RightParent, Constants::RIGHT_PARENT),
                                                     Token(TokenType::LeftBrace, Constants::LEFT_BRACE),
                                                     Token(TokenType::RightBrace, Constants::RIGHT_BRACE),
                                                     Token(TokenType::Comma, Constants::COMMA),
                                                     Token(TokenType::Semicolon, Constants::SEMICOLON) } },
                            ScriptData{ "let one = 1;"
                                        "let twenty = 20;"
                                        "let result = func add(x, y) {"
                                        "  x + y;"
                                        "};"
                                        "if (left >= right) {"
                                        "   return a > b;"
                                        "} else {"
                                        "   return a != b"
                                        "};"
                                        "if (left <= right) {"
                                        "   return a < b;"
                                        "} else {"
                                        "   return a == b"
                                        "};",
                                        {
                                            // line 1;
                                            Token(TokenType::Let, Constants::LET),
                                            Token(TokenType::Identifier, "one"),
                                            Token(TokenType::Assign, Constants::ASSIGN),
                                            Token(TokenType::Identifier, "1"),
                                            Token(TokenType::Semicolon, Constants::SEMICOLON),

                                            // line 2;
                                            Token(TokenType::Let, Constants::LET),
                                            Token(TokenType::Identifier, "twenty"),
                                            Token(TokenType::Assign, Constants::ASSIGN),
                                            Token(TokenType::Identifier, "20"),
                                            Token(TokenType::Semicolon, Constants::SEMICOLON),

                                            // line 3-5(function call);
                                            Token(TokenType::Let, Constants::LET),
                                            Token(TokenType::Identifier, "result"),
                                            Token(TokenType::Assign, Constants::ASSIGN),
                                            Token(TokenType::Func, "func"),
                                            Token(TokenType::Identifier, "add"),
                                            Token(TokenType::LeftParent, Constants::LEFT_PARENT),
                                            Token(TokenType::Identifier, "x"),
                                            Token(TokenType::Comma, Constants::COMMA),
                                            Token(TokenType::Identifier, "y"),
                                            Token(TokenType::RightParent, Constants::RIGHT_PARENT),
                                            Token(TokenType::LeftBrace, Constants::LEFT_BRACE),
                                            Token(TokenType::Identifier, "x"),
                                            Token(TokenType::Plus, Constants::PLUS),
                                            Token(TokenType::Identifier, "y"),
                                            Token(TokenType::Semicolon, Constants::SEMICOLON),
                                            Token(TokenType::RightBrace, Constants::RIGHT_BRACE),
                                            Token(TokenType::Semicolon, Constants::SEMICOLON),

                                            // line 6-10( ... if $left >= $right)
                                            Token(TokenType::If, Constants::IF),
                                            Token(TokenType::LeftParent, Constants::LEFT_PARENT),
                                            Token(TokenType::Identifier, "left"),
                                            Token(TokenType::Ge, Constants::GREATER_EQUAL),
                                            Token(TokenType::Identifier, "right"),
                                            Token(TokenType::RightParent, Constants::RIGHT_PARENT),
                                            Token(TokenType::LeftBrace, Constants::LEFT_BRACE),
                                            Token(TokenType::Return, Constants::RETURN),
                                            Token(TokenType::Identifier, "a"),
                                            Token(TokenType::Gt, Constants::GREATER_THEN),
                                            Token(TokenType::Identifier, "b"),
                                            Token(TokenType::Semicolon, Constants::SEMICOLON),
                                            Token(TokenType::RightBrace, Constants::RIGHT_BRACE),
                                            Token(TokenType::Else, Constants::ELSE),
                                            Token(TokenType::LeftBrace, Constants::LEFT_BRACE),
                                            Token(TokenType::Return, Constants::RETURN),
                                            Token(TokenType::Identifier, "a"),
                                            Token(TokenType::Ne, Constants::NOT_EQUAL),
                                            Token(TokenType::Identifier, "b"),
                                            Token(TokenType::RightBrace, Constants::RIGHT_BRACE),
                                            Token(TokenType::Semicolon, Constants::SEMICOLON),

                                            // line 11-16( ... if $left <= $right)
                                            Token(TokenType::If, Constants::IF),
                                            Token(TokenType::LeftParent, Constants::LEFT_PARENT),
                                            Token(TokenType::Identifier, "left"),
                                            Token(TokenType::Le, Constants::LESS_EQUAL),
                                            Token(TokenType::Identifier, "right"),
                                            Token(TokenType::RightParent, Constants::RIGHT_PARENT),
                                            Token(TokenType::LeftBrace, Constants::LEFT_BRACE),
                                            Token(TokenType::Return, Constants::RETURN),
                                            Token(TokenType::Identifier, "a"),
                                            Token(TokenType::Lt, Constants::LESS_THEN),
                                            Token(TokenType::Identifier, "b"),
                                            Token(TokenType::Semicolon, Constants::SEMICOLON),
                                            Token(TokenType::RightBrace, Constants::RIGHT_BRACE),
                                            Token(TokenType::Else, Constants::ELSE),
                                            Token(TokenType::LeftBrace, Constants::LEFT_BRACE),
                                            Token(TokenType::Return, Constants::RETURN),
                                            Token(TokenType::Identifier, "a"),
                                            Token(TokenType::Eq, Constants::EQUAL),
                                            Token(TokenType::Identifier, "b"),
                                            Token(TokenType::RightBrace, Constants::RIGHT_BRACE),
                                            Token(TokenType::Semicolon, Constants::SEMICOLON),
                                        } }
                            ));
// clang-format on
