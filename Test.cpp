#include "Board.hpp"
#include "doctest.h"
#include <string>
#include <algorithm>



std::string nospaces(std::string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

ariel::Board board;

TEST_CASE("Good post code") {
	board.post(100,200, ariel::Direction::Horizontal,"This");
	board.post(100,300, ariel::Direction::Horizontal,"ain't");
	board.post(100,400, ariel::Direction::Horizontal,"a");
	board.post(100,500, ariel::Direction::Horizontal,"song");
	board.post(100,600, ariel::Direction::Horizontal,"for");
	board.post(100,700, ariel::Direction::Horizontal,"the");
	board.post(100,800, ariel::Direction::Horizontal,"broken");
	board.post(100,900, ariel::Direction::Horizontal,"-");
	board.post(100,1000, ariel::Direction::Horizontal,"hearted");
	
	board.post(200,200, ariel::Direction::Horizontal,"No");
	board.post(200,300, ariel::Direction::Horizontal,"silent");
	board.post(200,400, ariel::Direction::Horizontal,"prayer");
	board.post(200,500, ariel::Direction::Horizontal,"for");
	board.post(200,600, ariel::Direction::Horizontal,"faith");
	board.post(200,700, ariel::Direction::Horizontal,"-");
	board.post(200,800, ariel::Direction::Horizontal,"departed");
	
	board.post(300,200, ariel::Direction::Horizontal,"And");
	board.post(300,400, ariel::Direction::Horizontal,"I");
	board.post(300,500, ariel::Direction::Horizontal,"ain't");
	board.post(300,600, ariel::Direction::Horizontal,"gonna");
	board.post(300,700, ariel::Direction::Horizontal,"be");
	board.post(300,800, ariel::Direction::Horizontal,"just");
	board.post(300,900, ariel::Direction::Horizontal,"a");
	board.post(300,1000, ariel::Direction::Horizontal,"face");
	board.post(300,1100, ariel::Direction::Horizontal,"in");
	board.post(300,1200, ariel::Direction::Horizontal,"the");
	board.post(300,1300, ariel::Direction::Horizontal,"crowd");
	
	board.post(400,200, ariel::Direction::Horizontal,"You're");
	board.post(400,300, ariel::Direction::Horizontal,"gonna");
	board.post(400,400, ariel::Direction::Horizontal,"hear");
	board.post(400,500, ariel::Direction::Horizontal, "my");
	board.post(400,600, ariel::Direction::Horizontal, "voice");
	board.post(400,700, ariel::Direction::Horizontal, "when");
	board.post(400,800, ariel::Direction::Horizontal,"I");
	board.post(400,900, ariel::Direction::Horizontal,"shout");
	board.post(400,1000, ariel::Direction::Horizontal,"it");
	board.post(400,1100, ariel::Direction::Horizontal,"out");
	board.post(400,1200, ariel::Direction::Horizontal,"loud");
	
	board.post(500,400, ariel::Direction::Horizontal,"........");
	
	board.post(600,300, ariel::Direction::Horizontal,"It's");
	board.post(600,400, ariel::Direction::Horizontal,"my");
	board.post(600,500, ariel::Direction::Horizontal,"life");
	
	board.post(600,300, ariel::Direction::Horizontal,"It's");
	board.post(600,400, ariel::Direction::Horizontal,"now");
	board.post(600,500, ariel::Direction::Horizontal,"or");
	board.post(600,600, ariel::Direction::Horizontal,"never");
	
	board.post(700,200, ariel::Direction::Horizontal, "But");
	board.post(700,300, ariel::Direction::Horizontal, "I");
	board.post(700,400, ariel::Direction::Horizontal, "gonna");
	board.post(700,500, ariel::Direction::Horizontal, "live");
	board.post(700,600, ariel::Direction::Horizontal, "forever");
	
	board.post(800,400, ariel::Direction::Horizontal, "..........");
												
    CHECK(board.read(100,200, ariel::Direction::Horizontal, 4) == nospaces("This"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 5) == nospaces("ain't"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 1) == nospaces("a"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 4) == nospaces("song"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 3) == nospaces("for"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 3) == nospaces("the"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 6) == nospaces("broken"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 1) == nospaces("-"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 6) == nospaces("hearth"));
	
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 2) == nospaces("No"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 5) == nospaces("silent"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 6) == nospaces("prayer"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 3) == nospaces("for"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 5) == nospaces("faith"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 1) == nospaces("-"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 6) == nospaces("departed"));
	
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 3) == nospaces("And"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 2) == nospaces("I"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 4) == nospaces("ain't"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 5) == nospaces("gonna"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 2) == nospaces("be"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 4) == nospaces("just"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 1) == nospaces("a"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 4) == nospaces("face"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 2) == nospaces("in"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 3) == nospaces("the"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 5) == nospaces("crowd"));
	
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 6) == nospaces("You're"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 5) == nospaces("gonna"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 4) == nospaces("hear"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 2) == nospaces("my"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 5) == nospaces("voice"));
	
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 4) == nospaces("when"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 1) == nospaces("I"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 5) == nospaces("shout"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 2) == nospaces("it"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 3) == nospaces("out"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 4) == nospaces("loud"));
	
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 8) == nospaces("........"));
	
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 4) == nospaces("It's"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 2) == nospaces("my"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 4) == nospaces("life"));
	
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 4) == nospaces("It's"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 3) == nospaces("now"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 2) == nospaces("or"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 5) == nospaces("never"));
	
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 1) == nospaces("I"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 5) == nospaces("ain't"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 5) == nospaces("gonna"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 4) == nospaces("live"));
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 7) == nospaces("forever"));
	
	CHECK(board.read(100,200, ariel::Direction::Horizontal, 10) == nospaces(".........."));

}

TEST_CASE("Bad post code") {
	CHECK_THROWS(board.post(3000,200, ariel::Direction::Horizontal, "abcd"));
    CHECK_THROWS(board.read(100,200, ariel::Direction::Horizontal, 3));

}