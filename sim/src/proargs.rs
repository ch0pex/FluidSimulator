use std::io::{Error, ErrorKind};

pub struct ProArgs {
    pub nts: usize,
    pub input_file: String,
    pub output_file: String,
}

impl ProArgs {
    pub fn new(args: Vec<String>) -> ProArgs {
        ProArgs { args }
    }

    pub fn check_count(&self) -> Result<(), Error> {
        match self.args.len() {
            4 => Ok(()),
            _ => Err(Error::from(ErrorKind::InvalidInput)),
        }
    }

    pub fn check_nts(&self) -> usize {
        self.args[2]
            .parse::<usize>()
            .expect("Invalid nts, nts must be a number")
    }
}

