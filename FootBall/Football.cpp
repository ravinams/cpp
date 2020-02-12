/* Please note: even though it says IMPLEMENT ME, in some cases
   the implementation can be empty. In fact, you may wish to remove
   some of the functions entirely
*/
#include "Football.h"

// -------------- Team --------------------

Team::Team(const string& name) {
	m_name = name ;
	m_goalsConceded = 0 ;
}

void Team::addGoalsConceded(int g) {
	m_goalsConceded  =  m_goalsConceded + g  ;
}

Team::~Team() {
	// IMPLEMENT ME
}

string Team::getName() const 
{
	return m_name ;
}

int Team::getGoalsConceded() const 
{
	return m_goalsConceded ;
}
// -------------- Player ------------------

Player::Player() {
	// see comment in .h
}

Player::Player(const string& name, Team* t) {
	// IMPLEMENT ME
	m_name = name ;
	m_team = t ;
	m_goalsScored = 0 ;
	m_assists  = 0;	
}

// don't remove this even if you want to make the destructor pure virtual
Player::~Player() {
	// IMPLEMENT ME
	 // if (m_team != nullptr)
	 // 	  //delete m_team ;
}

void Player::addGoalsScored(int g) {	
	// IMPLEMENT ME
	m_goalsScored = m_goalsScored + g ;
}

void Player::addAssists(int a) {
	// IMPLEMENT ME
	m_assists =m_assists + a  ;
}

// void Player::addGoalsConceded(int ss )
// {
// 	m_goalsConceded = m_goalsConceded + ss;
// }

int Player::getScore() const {
	// IMPLEMENT ME
}

string Player::print() const {
	// IMPLEMENT ME
}

string Player::getName() const
{
	return m_name ;
}

 Team* Player::getTeam() const
 {
 	return m_team ;
 }

// -------------- Attacker ------------------

Attacker::Attacker(const string& name, Team* t) : Player(name,t) {
	
}

Attacker::~Attacker() {
	// IMPLEMENT ME
}

int Attacker::getScore() const {		
	return m_goalsScored * 4 + m_assists * 3  ;
}

string Attacker::print() const {

	string s = "Attacker: "+getName()+", Team: "+getTeam()->getName()+"\n";
	s += " Goals scored: "+to_string(m_goalsScored)+"\n";
	s += " Assists: "+to_string(m_assists)+"\n";
	s += " Goals conceded: "+to_string(getTeam()->getGoalsConceded())+"\n";
	s += " Score: "+to_string(getScore()) ;

	return s ;
}

// -------------- Midfielder ------------------

Midfielder::Midfielder(const string& name, Team* t):Player(name,t) {
	// IMPLEMENT ME
}

Midfielder::~Midfielder() {
	// IMPLEMENT ME
}

int Midfielder::getScore() const {

	int teamGC = getTeam()->getGoalsConceded() ;
	return ( m_goalsScored * 5 + m_assists * 3 + ( teamGC == 0 ? 1 : 0 )) ;
}

string Midfielder::print() const {

string s = "Midfielder: "+getName()+", Team: "+getTeam()->getName()+"\n";
	s += " Goals scored: "+to_string(m_goalsScored)+"\n";
	s += " Assists: "+to_string(m_assists)+"\n";
	s += " Goals conceded: "+to_string(getTeam()->getGoalsConceded())+"\n";
	s += " Score: "+to_string(getScore()) ;

	return s ;
}

// -------------- Defender ------------------

Defender::Defender(const string& name, Team* t):Player(name,t){
	// IMPLEMENT ME
}

Defender::~Defender() {
	// IMPLEMENT ME
}

int Defender::getScore() const {
	int teamGC = getTeam()->getGoalsConceded() ;
	return ( m_goalsScored * 6 + m_assists * 3 + ( teamGC == 0 ? 4 : -1 * teamGC/2 )) ;
}

string Defender::print() const {

	string s = "Defender: "+getName()+", Team: "+getTeam()->getName()+"\n";
	s += " Goals scored: "+to_string(m_goalsScored)+"\n";
	s += " Assists: "+to_string(m_assists)+"\n";
	s += " Goals conceded: "+to_string(getTeam()->getGoalsConceded())+"\n";
	s += " Score: "+to_string(getScore()) ;

	return s ;
}

// -------------- Goalkeeper ------------------

Goalkeeper::Goalkeeper(const string& name, Team* t) : Player(name,t) {	
	m_shotsSaved = 0 ;
}

Goalkeeper::~Goalkeeper() {
	// IMPLEMENT ME
}

void Goalkeeper::addShotsSaved(int ss) {
	m_shotsSaved  = m_shotsSaved + ss ;
}

int Goalkeeper::getScore() const {
	int teamGC = getTeam()->getGoalsConceded() ;
	return ( m_goalsScored * 6 + m_assists * 3 + ( teamGC == 0 ? 4 : -1 * teamGC/2 ) + m_shotsSaved/3) ;
}

string Goalkeeper::print() const {

    string s = "Goalkeeper: "+getName()+", Team: "+getTeam()->getName()+"\n";
	s += " Goals scored: "+to_string(m_goalsScored)+"\n";
	s += " Assists: "+to_string(m_assists)+"\n";
	s += " Goals conceded: "+to_string(getTeam()->getGoalsConceded())+"\n";
	s += " Shots saved: "+to_string(m_shotsSaved)+"\n";
	s += " Score: "+to_string(getScore());

	return s ;
}

// -------------- FantasyTeam ------------------

FantasyTeam::FantasyTeam() {
	// IMPLEMENT ME
	m_size = 0 ;
}

FantasyTeam::~FantasyTeam() {
	for (int i = 0 ; i < m_size ; i++)
		  if ( players[i] != nullptr)
		  	     {
		  	        //if ( players[i] -> getTeam() != nullptr )
		  	        	  //delete players[i] -> getTeam() ;
		  	        delete players[i] ;
		  	      }
}

bool FantasyTeam::addPlayer(Player* p) {
	 if (m_size == 11 )
	 	  return false ;
	 else
	 {
      
       for (int i = 0 ; i < m_size ; i++)
       	  if ( players[i]->getName().compare(p->getName()) == 0 )
       	  	   return false ;
	 }
	 players[m_size++]=p ;
	 return true  ;
}

int FantasyTeam::getScore() const {
	
	int score = 0;
	for (int i = 0 ; i < m_size ; i++)
		 score = score + players[i]->getScore() ;
	return score;
}

