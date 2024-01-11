const Moves = {
    ROCK: 'rock',
    PAPER: 'paper',
    SCISSORS: 'scissors' 
};

const Outcomes = {
    WIN: 'win',
    LOSE: 'lose',
    TIE: 'tie'
};

const score = JSON.parse(localStorage.getItem('score')) || {
    wins: 0,
    losses: 0,
    ties: 0
};

function generateComputerChoice() {
    const rand = Math.random();
    if (rand < 0.33) {
        return Moves.ROCK;
    } else if (rand >= 0.33 && rand < 0.66) {
        return Moves.PAPER;
    } else {
        return Moves.SCISSORS;
    }
}

function playMove(userMove, computerMove) {
    let outcome = Outcomes.TIE;

    if (userMove === Moves.ROCK) {
        if (computerMove === Moves.ROCK) {
            // Do nothing.
        } else if (computerMove === Moves.PAPER) {
            outcome = Outcomes.LOSE;
        } else if (computerMove === Moves.SCISSORS) {
            outcome = Outcomes.WIN;
        }
    } else if (userMove === Moves.PAPER) {
        if (computerMove === Moves.ROCK) {
            outcome = Outcomes.WIN;
        } else if (computerMove === Moves.PAPER) {
            // Do nothing.
        } else if (computerMove === Moves.SCISSORS) {
            outcome = Outcomes.LOSE;
        }
    } else if (userMove === Moves.SCISSORS) {
        if (computerMove === Moves.ROCK) {
            outcome = Outcomes.LOSE;
        } else if (computerMove === Moves.PAPER) {
            outcome = Outcomes.WIN;
        } else if (computerMove === Moves.SCISSORS) {
            // Do nothing.
        }
    }

    return outcome;
}

function updateScore(outcome) {
    if (outcome === Outcomes.WIN) {
        score.wins++;
    } else if (outcome === Outcomes.TIE) {
        score.ties++;
    } else if (outcome === Outcomes.LOSE) {
        score.losses++;
    }
}


function playGame(userMove) {
    const computerMove = generateComputerChoice();
    const outcome = playMove(userMove, computerMove);

    updateScore(outcome);

    printResults(userMove, computerMove, outcome);

    localStorage.setItem('score', JSON.stringify(score));
}

function reset() {
    score.wins = 0;
    score.losses = 0;
    score.ties = 0;
    localStorage.removeItem('score');

    printScore();
}

function printScore() {
    const scoreElement = document.querySelector('.js-score');
    scoreElement.innerHTML = `Wins: ${score.wins}, Losses: ${score.losses}, Ties: ${score.ties}`;
}

function prettyPrintOutcome(outcome) {
    const outcomeElement = document.querySelector('.js-outcome');
    if (outcome === Outcomes.WIN) {
        outcomeElement.innerHTML = 'You win!';
    } else if (outcome === Outcomes.TIE) {
        outcomeElement.innerHTML = 'Tie.';
    } else if (outcome === Outcomes.LOSE) {
        outcomeElement.innerHTML = 'You lose.';
    }
}

function printResults(userMove, computerMove, outcome) {
    prettyPrintOutcome(outcome);

    const resultElement = document.querySelector('.js-moves');
    resultElement.innerHTML = `You
        <img src="img/${userMove}-emoji.png" class="move-icon">
        <img src="img/${computerMove}-emoji.png" class="move-icon">
        Computer`;

    printScore();
}

printScore();