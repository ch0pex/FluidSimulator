use std::io::Error;

use crate::grid::Grid;
use crate::proargs::ProArgs;

pub struct Simulator {
    args: ProArgs,
    grid: Option<Grid>,
    nts: usize,
}

impl Simulator {
    pub fn new(args: Vec<String>) -> Simulator {
        Simulator {
            args: ProArgs::new(args),
            grid: None,
            nts: 0,
        }
    }

    pub fn init_sim(&self) {}

    pub fn process_sim(&self) {}

    pub fn store_results(&self) {}
}

